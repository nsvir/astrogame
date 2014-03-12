/*
** animation_monster.c for monster in /home/parejo_p/rush/toto/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 17:22:02 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 22:19:09 2014 lefebv_z
*/
#include	"my_sdl.h"
#include	"animation.h"

static int	condition(t_character *self, t_animation *anim)
{
  t_map		*map;
  int		x;
  int		y;

  map = anim->map;
  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  if (self->status == LEFT || self->status == RIGHT)
    x += ((self->status == 4) ? (-1) : (1));
  if (x < 0 || x >= map->column)
    return (FAILURE);
  if (anim->display->type[(int)map->map[y][x]] != BLOCK
      && anim->display->type[(int)map->map[y + 1][x]] != EMPTY)
    return (SUCCESS);
  return (FAILURE);
}

static void	do_anim(t_character *self, t_animation *anim)
{
  if (self->status == LEFT)
    animation_left(self, anim);
  else
    animation_right(self, anim);
}

int		animation_monster(t_character *self, t_animation *anim)
{
  int		tmp;

  if (self->wait == 0)
    {
      if (condition(self, anim) == SUCCESS)
	do_anim(self, anim);
      else
	{
	  self->status = ((self->status == LEFT) ? (RIGHT) : (LEFT));
	  if (condition(self, anim) == SUCCESS)
	    do_anim(self, anim);
	}
    }
  else
    {
      tmp = self->status;
      do_anim(self, anim);
      self->status = tmp;
      self->wait--;
    }
  return (SUCCESS);
}
