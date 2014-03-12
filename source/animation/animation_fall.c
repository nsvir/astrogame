/*
** animation_fall.c for animation_fall in /home/parejo_p/rush/toto/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 22:20:25 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 23:34:24 2014 nicolas svirchevsky
*/
#include	"animation.h"
#include	"my_sdl.h"

int		is_grounded(t_character *self, t_animation *anim)
{
  int		x;
  int		y;

  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  if (anim->display->type[(int)anim->map->map[y][x]] == LADDER)
    return (SUCCESS);
  y++;
  if (x < 0 || y < 0 || x >= anim->map->column || y >= anim->map->line)
    return (SUCCESS);
  if (anim->display->type[(int)anim->map->map[y][x]] != BLOCK
      && anim->display->type[(int)anim->map->map[y][x]] != LADDER)
    return (FAILURE);
  return (SUCCESS);
}

static void	fall_wait(t_character *self, t_animation *anim)
{
  if (self->wait == 0)
    self->wait = 3;
  else if (self->wait == 1 && is_grounded(self, anim) == FAILURE)
    {
      self->gravity += self->gravity;
      if (self->gravity >= 8)
	self->gravity = 16;
    }
  else if (self->wait == 1)
    {
      self->gravity = 1;
      self->status ^= FALL;
    }
}

void		fall(t_character *self, t_animation *anim)
{
  double	i;
  int		j;

  self->status |= FALL;
  i = ((BLOCKSIZE / 4.0) * self->gravity) / BLOCKSIZE;
  if (i > (int)i)
    i = (int)i + 1;
  j = 0;
  while (j < i && is_grounded(self, anim) == FAILURE)
    {
      self->pos_y += ((BLOCKSIZE / 4.0) * self->gravity) / i;
      j++;
    }
  fall_wait(self, anim);
}
