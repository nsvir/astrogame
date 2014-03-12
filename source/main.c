/*
** main.c for  in /home/svirch_n/game/source
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 10:20:15 2014 nicolas svirchevsky
** Last update Wed Mar 12 00:04:26 2014 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<SDL/SDL_image.h>
#include	"event.h"
#include	"animation.h"
#include	"error.h"
#include	"my_sdl.h"
#include	"menu.h"
#include	"parser.h"
#include	"free.h"

static int	init_sdl(t_display *display)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (sdl_error("Can't init SDL"));
  if (TTF_Init() == -1)
    return (sdl_error("Can't init TTF"));
  if (init_window(&(display->screen), MENU_W, MENU_H))
    return (FAILURE);
  load_types(display->type);
  if (load_sprites(display->sprites))
    return (my_error("Can't load sprites"));
  if (load_enemy(display->enemy))
    return (my_error("Can't load ennemie sprites"));
  if (load_player(display->player))
    return (my_error("Can't load player sprites"));
  return (SUCCESS);
}

int		init_window(SDL_Surface **screen, int w, int h)
{
  SDL_Surface	*icon;

  icon = IMG_Load("./sprites/Player/p1_duck.png");
  if (icon)
    SDL_WM_SetIcon(icon, NULL);
  else
    printf("Epikong : Warning : Icon not found\n");
  *screen = SDL_SetVideoMode(w, h, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (*screen == NULL)
    return (sdl_error("Can't set video mode"));
  SDL_WM_SetCaption("EpiKong", NULL);
  return (SUCCESS);
}

int		main(int argc, const char *argv[])
{
  t_character	*players;
  t_display	display;
  t_map		*map;
  int		quit;

  if (argc != 1)
    return (my_error("Usage : ./epikong"));
  (void)argv;
  if (init_sdl(&display))
    return (1);
  quit = 0;
  map = NULL;
  quit = menu(display.screen, display.sprites, &map);
  if (quit == FAILURE)
    return (1);
  if (quit == SUCCESS)
    return (my_exit(NULL, &display));
  if ((players = parser_create(map, &display)) == NULL)
    return (FAILURE);
  show_map(map, display.screen, display.sprites, players);
  SDL_Flip(display.screen);
  return (animation(map, &display, players));
}
