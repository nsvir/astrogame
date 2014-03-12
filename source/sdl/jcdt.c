/*
** jcdt.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 23:05:35 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:23:33 2014 nicolas svirchevsky
*/


#include	<SDL/SDL.h>
#include	"my_sdl.h"
#include	"animation.h"

static int	jcdt_left(t_animation *anim, t_character *self)
{
  t_map		*map;
  enum e_type	*types;
  int		x;
  int		y;

  map = anim->map;
  types = anim->display->type;
  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  y -= 1;
  x -= 1;
  if (y >= map->line || x >= map->column)
    return (0);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (0);
  if (types[(int)map->map[y][x]] == LADDER)
    return (1);
  y += 1;
  x -= 1;
  if (y >= map->line || x >= map->column)
    return (1);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (1);
  return (2);
}

static int	jcdt_right(t_animation *anim, t_character *self)
{
  t_map		*map;
  enum e_type	*types;
  int		x;
  int		y;

  map = anim->map;
  types = anim->display->type;
  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  y -= 1;
  x += 1;
  if (y >= map->line || x >= map->column)
    return (0);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (0);
  if (types[(int)map->map[y][x]] == LADDER)
    return (1);
  y += 1;
  x += 1;
  if (y >= map->line || x >= map->column)
    return (1);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (1);
  return (2);

}

int		jcdt(int type, t_animation *anim, t_character *self)
{
  t_map		*map;
  enum e_type	*types;
  int		x;
  int		y;

  if (type == RIGHT)
    return (jcdt_right(anim, self));
  if (type == LEFT)
    return (jcdt_left(anim, self));
  map = anim->map;
  types = anim->display->type;
  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  y -= 1;
  if (y >= map->line || x >= map->column)
    return (0);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (0);
  y -= 1;
  if (y >= map->line || x >= map->column)
    return (1);
  if (types[(int)map->map[y][x]] == BLOCK)
    return (1);
  return (2);
}

