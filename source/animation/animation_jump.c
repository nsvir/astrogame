/*
** animation_jump.c<2> for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 22:03:52 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:28:11 2014 nicolas svirchevsky
*/

#include	"my_sdl.h"
#include	"animation.h"

static void	leave(t_character *self)
{
  if (self->wait == 1)
    {
      self->status = 0;
      self->bck = 0;
    }
}

void		my_bck(t_character *self, int bck)
{
  self->bck = bck;
  self->wait = 4 * self->bck - 1;
}

void	animation_jump_left(t_character *self, t_animation *anim, int bck)
{
  if (self->bck == 0)
    my_bck(self, bck);
  self->status |= LEFT;
  self->status |= JUMP;
  if (self->bck == 2)
    {
      if (self->wait > 4)
	{
	  self->pos_x -= (BLOCKSIZE) / 4.0;
	  self->pos_y -= (BLOCKSIZE) / 4.0;
	}
      else if (self->wait <= 4)
	{
	  self->pos_x -= (BLOCKSIZE) / 4.0;
	  self->pos_y += (BLOCKSIZE) / 4.0;
	}
    }
  else
    {
      self->pos_x -= (BLOCKSIZE) / 4.0;
      self->pos_y -= (BLOCKSIZE) / 4.0;
    }
  (void) anim;
  return (leave(self));
}

void	animation_jump_right(t_character *self, t_animation *anim, int bck)
{
  if (self->bck == 0)
    my_bck(self, bck);
  self->status |= RIGHT;
  self->status |= JUMP;
  if (self->bck == 2)
    {
      if (self->wait > 4)
	{
	  self->pos_x += (BLOCKSIZE) / 4.0;
	  self->pos_y -= (BLOCKSIZE) / 4.0;
	}
      else if (self->wait <= 4)
	{
	  self->pos_x += (BLOCKSIZE) / 4.0;
	  self->pos_y += (BLOCKSIZE) / 4.0;
	}
    }
  else
    {
      self->pos_x += (BLOCKSIZE) / 4.0;
      self->pos_y -= (BLOCKSIZE) / 4.0;
    }
  (void) anim;
  return (leave(self));
}

void	animation_jump(t_character *self, t_animation *anim, int bck)
{
  if (self->bck == 0)
    {
      self->bck = bck;
      self->wait = 4 * self->bck - 1;
    }
  self->status |= JUMP;
  self->pos_y -= (BLOCKSIZE) / 4.0;
  (void) anim;
  return (leave(self));
}
