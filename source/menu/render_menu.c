/*
** rendu_menu.c for epikong in /home/marie/modules/unix/rush/T2Rush1/etape_2
** 
** Made by lefebv_z
** Login   <marie@epitech.net>
** 
** Started on  Sat Mar  8 23:05:03 2014 lefebv_z
** Last update Sun Mar  9 23:40:29 2014 lefebv_z
*/

#include	<SDL/SDL_ttf.h>
#include	<SDL/SDL_rotozoom.h>
#include	"menu.h"
#include	"error.h"
#include	"my_sdl.h"

static int	show_previews(SDL_Surface *screen, SDL_Surface **images)
{
  int		i;
  double	zoom[2];
  int		pos[2];
  SDL_Surface	*previews[5];

  i = 0;
  while (i < 5)
    {
      zoom[0] = (double)PR_W(screen->w) / images[i]->w;
      zoom[1] = (double)PR_H(screen->h) / images[i]->h;
      if (!(previews[i] = zoomSurface(images[i], zoom[0], zoom[1], 0)))
      	return (FAILURE);
      SDL_FreeSurface(images[i]);
      pos[0] = PR_X(i, screen->w);
      pos[1] = PR_Y(i, screen->h);
      apply_surface(pos[0], pos[1], previews[i], screen);
      SDL_FreeSurface(previews[i]);
      i++;
    }
  return (SUCCESS);
}

static SDL_Surface	*get_msg(char *str)
{
  TTF_Font		*font;
  SDL_Color		textColor;
  SDL_Surface		*msg;

  textColor.r = 255;
  textColor.g = 255;
  textColor.b = 255;
  if (!(font = TTF_OpenFont("CaslonBold.ttf", 28)))
    return (NULL);
  msg = TTF_RenderText_Solid(font, str, textColor);
  TTF_CloseFont(font);
  return (msg);
}

int	render_menu(SDL_Surface *screen, SDL_Surface **images)
{
  SDL_Surface	*msg;

  if (!(msg = get_msg(WELCOME)))
    return (sdl_error("Can't load ttf message"));
  if (show_previews(screen, images))
    return (sdl_error("Can't show previews"));
  apply_surface(0, 0, msg, screen);
  SDL_Flip(screen);
  SDL_FreeSurface(msg);
  return (SUCCESS);
}
