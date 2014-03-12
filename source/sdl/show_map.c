/*
** show_map.c for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 19:22:19 2014 nicolas svirchevsky
** Last update Sun Mar  9 19:25:51 2014 lefebv_z
*/

#include	"my_sdl.h"

static int	apply_characters(t_character *characters, SDL_Surface *screen)
{
  double	x;
  double	y;

  while (characters)
    {
      x = characters->pos_x;
      y = characters->pos_y;
      apply_surface(x, y, characters->current, screen);
      characters = characters->next;
    }
  return (SUCCESS);
}

int		show_map(t_map *map, SDL_Surface *screen,	\
			 SDL_Surface **sprites, t_character *characters)
{
  int		i;
  int		j;
  SDL_Surface	*surface;

  i = -1;
  SDL_FillRect(screen, NULL, 0x000D647F);
  while (++i < map->line)
    {
      j = -1;
      while (++j < map->column)
	{
	  if ((surface = sprites[(int)map->map[i][j]]) != NULL)
	    apply_surface(BLOCKSIZE * j, BLOCKSIZE * i, surface, screen);
	}
    }
  apply_characters(characters, screen);
  SDL_Flip(screen);
  return (SUCCESS);
}
