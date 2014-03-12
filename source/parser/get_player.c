/*
** get_player.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 23:28:56 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:28:56 2014 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	"my_sdl.h"
#include	"parser.h"
#include	"animation.h"

static void		*create_player(int i, int j, SDL_Surface **player)
{
  t_character	*result;

  if ((result = malloc(sizeof(*result))) == NULL)
    return (NULL);
  result->wait = 0;
  result->bck = 0;
  result->animate = &animation_player;
  result->current = player[3];
  result->status = 0;
  result->gravity  = 1;
  result->current_pos = 3;
  result->pos_x = j * BLOCKSIZE;
  result->pos_y = i * BLOCKSIZE;
  result->is_enemy = 0;
  result->next = NULL;
  return (result);
}

void		*get_player(t_map *map, SDL_Surface **player)
{
  t_character	*result;
  int		i;
  int		j;

  i = -1;
  result = NULL;
  while (++i < map->line)
    {
      j = -1;
      while (++j < map->column)
	{
	  if (map->map[i][j] == 'i')
	    {
	      if (result != NULL)
		return (pcerror("Multiple players defined"));
	      if ((result = create_player(i, j, player)) == NULL)
		return (pcerror("Could not malloc"));
	    }
	}
    }
  return ((!result) ? (pcerror("Could not found the beginning")) : (result));
}
