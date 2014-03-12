/*
** free.c for epikong in /home/marie/modules/unix/rush/T2Rush1/etape_2
** 
** Made by lefebv_z
** Login   <marie@epitech.net>
** 
** Started on  Sun Mar  9 16:55:47 2014 lefebv_z
** Last update Sun Mar  9 17:14:31 2014 lefebv_z
*/

#include	<SDL/SDL_ttf.h>
#include	"display.h"
#include	"parser.h"

int		free_map(t_map *map)
{
  int		i;

  if (!map)
    return (SUCCESS);
  i = 0;
  while (i < map->line)
    {
      free(map->map[i]);
      i++;
    }
  free(map->map);
  return (SUCCESS);
}

int		my_exit(t_map *map, t_display *display)
{
  int		i;

  free_map(map);
  SDL_FreeSurface(display->screen);
  i = 0;
  while (i < 255)
    {
      if (display->sprites[i] != NULL)
	SDL_FreeSurface(display->sprites[i]);
      i++;
    }
  SDL_Quit();
  TTF_Quit();
  return (SUCCESS);
}
