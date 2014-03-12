/*
** parser_create.c for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 22:16:31 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:09:28 2014 lefebv_z
*/

#include	<stdlib.h>
#include	"animation.h"
#include	"my_sdl.h"
#include	"parser.h"

static int	my_enemy_error(const char *str)
{
  printf("Parser: %s\n", str);
  return (FAILURE);
}

static int	find_enemy(t_map *map, int *i, int *j)
{
  (*j)++;
  while (*i < map->line)
    {
      if (*j == map->column)
	*j = 0;
      while (*j < map->column)
	{
	  if (map->map[*i][*j] == 'm')
	    return (SUCCESS);
	  (*j)++;
	}
      (*i)++;
    }
  return (FAILURE);
}

static void	set_enemies(t_character *current, SDL_Surface **spr)
{
  current->wait = 0;
  current->status = LEFT;
  current->gravity = 1;
  current->current = spr[3];
  current->current_pos = 3;
  current->is_enemy = 1;
  current->animate = &animation_monster;
  current->next = NULL;
}

static int	get_enemies(t_map *map, t_character *player, SDL_Surface **spr)
{
  t_character	*current;
  t_character	*tmp;
  int		i;
  int		j;

  i = 0;
  j = -1;
  tmp = NULL;
  while (find_enemy(map, &i, &j) != FAILURE)
    {
      if ((current = malloc(sizeof(*current))) == NULL)
	return (my_enemy_error("Could not malloc"));
      set_enemies(current, spr);
      current->pos_x = j * BLOCKSIZE;
      current->pos_y = i * BLOCKSIZE;
      if (tmp == NULL)
	tmp = player;
      tmp->next = current;
      tmp = current;
    }
  return (SUCCESS);
}

void		*parser_create(t_map *map, t_display *display)
{
  t_character	*result;

  if (parser_check(map) == FAILURE)
    return (NULL);
  if ((result = get_player(map, display->player)) == NULL)
    return (NULL);
  if ((get_enemies(map, result, display->enemy)) == FAILURE)
    return (NULL);
  return (result);
}
