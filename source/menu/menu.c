/*
** menu.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 19:08:01 2014 lefebv_z
** Last update Wed Mar 12 00:07:10 2014 nicolas svirchevsky
*/

#include	<SDL/SDL_rotozoom.h>
#include	<SDL/SDL_image.h>
#include	"my_sdl.h"
#include	"menu.h"
#include	"error.h"
#include	"free.h"

static int	load_maps_images(t_map **maps, SDL_Surface **images,	\
				 SDL_Surface **sprites)
{
  int		i;
  int		w;
  int		h;

  i = 0;
  while (i < 5)
    {
      w = maps[i]->column * BLOCKSIZE;
      h = maps[i]->line * BLOCKSIZE;
      images[i] = SDL_CreateRGBSurface(0, w, h, 32,		\
				       0x00ff0000, 0x0000ff00,	\
				       0x000000ff, 0x00000000);
      if (!(images[i]))
	return (sdl_error("Can't create image's surface"));
      if (show_map(maps[i], images[i], sprites, NULL))
      	return (FAILURE);
      ++i;
    }
  return (SUCCESS);
}

static int	open_maps(t_map **maps,		\
			  SDL_Surface **images, SDL_Surface **sprites)
{
  int		i;

  i = 0;
  while (i < 5)
    if (!(maps[i++] = malloc(sizeof(t_map))))
      return (my_error("Malloc fail"));
  if (parser_file("./maps/map1", maps[0])
      || parser_file("./maps/map2", maps[1])
      || parser_file("./maps/map3", maps[2])
      || parser_file("./maps/map4", maps[3])
      || parser_file("./maps/map5", maps[4]))
    return (FAILURE);
  return (load_maps_images(maps, images, sprites));
}

static int	init_game(SDL_Surface *screen, SDL_Surface **sprites,	\
			  t_map **maps, t_map **m)
{
  int		i;

  i = 0;
  while (i < 5)
    {
      if (maps[i] != (*m))
	free_map(maps[i]);
      ++i;
    }
  SDL_FreeSurface(screen);
  init_window(&screen, (*m)->column * BLOCKSIZE, (*m)->line * BLOCKSIZE);
  show_map((*m), screen, sprites, NULL);
  SDL_Flip(screen);
  return (2);
}

static int	my_manage_mouse(SDL_Surface *screen, SDL_Surface **sprites, \
				t_map **maps, t_map **m)
{
  int		x;
  int		y;
  int		i;
  int		pos[2];

  SDL_GetMouseState(&x, &y);
  i = 0;
  while (i < 5)
    {
      pos[0] = PR_X(i, screen->w);
      pos[1] = PR_Y(i, screen->h);
      if (x >= pos[0] && x <= (pos[0] + PR_W(screen->w))
	  && y >= pos[1] && y <= (pos[1] + PR_H(screen->h)))
	{
	  *m = maps[i];
	  return (init_game(screen, sprites, maps, m));
	}
      i++;
    }
  return (SUCCESS);
}

int		menu(SDL_Surface *screen, SDL_Surface **sprites,
		     t_map **map)
{
  t_map		*maps[5];
  SDL_Surface	*images[5];
  SDL_Event	event;
  int		choosed;

  if (open_maps(maps, images, sprites))
    return (my_error("Can't open maps for menu"));
  if (render_menu(screen, images) == -1)
    return (sdl_error("Can't render menu"));
  choosed = 0;
  while (SDL_WaitEvent(&event))
    {
      if (event.type == SDL_QUIT
	  || (event.type == SDL_KEYDOWN
	      && event.key.keysym.sym == SDLK_ESCAPE))
	return (SUCCESS);
      if (event.type == SDL_MOUSEBUTTONUP)
	{
	  if ((choosed = my_manage_mouse(screen, sprites, maps, map)) == 2)
	    return (2);
	  if (choosed == FAILURE)
	    return (FAILURE);
	}
    }
  return (FAILURE);
}
