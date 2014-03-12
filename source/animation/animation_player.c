/*
** animation_player.c for animation_player in /home/parejo_p/rush/toto/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 17:21:26 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 22:59:22 2014 nicolas svirchevsky
*/

#include	<SDL/SDL.h>
#include	"my_sdl.h"
#include	"animation.h"
#include	"event.h"
#include	"macro.h"

static void	show_sprite(t_character *self, t_animation *anim)
{
  show_map(anim->map, anim->display->screen, anim->display->sprites, self);
  SDL_Flip(anim->display->screen);
  SDL_Delay(50);
}

static void	animation_pl_status(t_character *self, t_animation *anim)
{
  if ((self->status & LEFT) != 0 && (self->status & JUMP) == 0)
    animation_left(self, anim);
  if ((self->status & RIGHT) != 0 && (self->status & JUMP) == 0)
    animation_right(self, anim);
  if ((self->status & UP) != 0)
    animation_up(self, anim);
  if ((self->status & DOWN) != 0)
    animation_down(self, anim);
  if ((self->status & FALL) != 0)
    fall(self, anim);
  if ((self->status & JUMP) != 0 && (self->status & RIGHT) != 0)
    animation_jump_right(self, anim, 0);
  else if ((self->status & JUMP) != 0 && (self->status & LEFT) != 0)
    animation_jump_left(self, anim, 0);
  else if ((self->status & JUMP))
    animation_jump(self, anim, 0);
  show_sprite(self, anim);
  self->wait--;
}

int	animation_player(t_character *self, t_animation *anim)
{
  if (self->wait == 0)
    {
      if (is_grounded(self, anim) == SUCCESS)
	{
	  if (SDL_WaitEvent(&(anim->event)))
	    if (event_handler(self, anim) == 1)
	      return (1);
	}
      else
	fall(self, anim);
      show_sprite(self, anim);
    }
  else
    animation_pl_status(self, anim);
  return (SUCCESS);
}
