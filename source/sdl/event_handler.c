/*
** event_handler.c for event_handler in /home/parejo_p/rush/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 10:01:03 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 23:37:09 2014 nicolas svirchevsky
*/

#include	<SDL/SDL.h>
#include	"my_sdl.h"
#include	"animation.h"
#include	"event.h"

static int	cdt(int type, t_animation *anim, t_character *self)
{
  t_map		*map;
  enum e_type	*types;
  int		x;
  int		y;

  map = anim->map;
  x = self->pos_x / BLOCKSIZE;
  y = self->pos_y / BLOCKSIZE;
  if (type == DOWN)
    y += 1;
  else if (type == LEFT || type == RIGHT)
    x += (type == 4) ? (-1) : (1);
  if (y >= map->line || x >= map->column)
    return (0);
  types = anim->display->type;
  if (type == UP)
    return (types[(int)map->map[y][x]] == LADDER);
  if (type == DOWN)
    return (types[(int)map->map[y][x]] != BLOCK);
  if (type == LEFT || type == RIGHT)
    return (types[(int)map->map[y][x]] != BLOCK);
  return (0);
}

void	second_event_handle(t_character *self, t_animation *anim)
{
  if (anim->keystates[SDLK_LEFT] == 1 && jcdt(LEFT, anim, self) > 0)
    animation_jump_left(self, anim, jcdt(LEFT, anim, self));
  else if (anim->keystates[SDLK_RIGHT] == 1 && jcdt(RIGHT, anim, self) > 0)
    animation_jump_right(self, anim, jcdt(RIGHT, anim, self));
  else if (jcdt(UP, anim, self) > 0 && anim->keystates[SDLK_RIGHT] == 0
	   && anim->keystates[SDLK_LEFT] == 0)
    animation_jump(self, anim, jcdt(UP, anim, self));
}


int	event_handler(t_character *self, t_animation *anim)
{
  if (anim->event.type == SDL_QUIT)
    return (1);
  else if (anim->event.type == SDL_KEYDOWN)
    {
      if (anim->keystates[SDLK_ESCAPE])
	return (1);
      else if (anim->keystates[SDLK_UP] && cdt(UP, anim, self))
	animation_up(self, anim);
      else if (anim->keystates[SDLK_DOWN] == 1 && cdt(DOWN, anim, self))
	animation_down(self, anim);
      else if (anim->keystates[SDLK_RIGHT] == 1
	       && anim->keystates[SDLK_SPACE] == 0 && cdt(RIGHT, anim, self))
	animation_right(self, anim);
      else if (anim->keystates[SDLK_LEFT] == 1
	       && anim->keystates[SDLK_SPACE] == 0 && cdt(LEFT, anim, self))
	animation_left(self, anim);
      else if (anim->keystates[SDLK_SPACE] == 1)
	second_event_handle(self, anim);
    }
  return (0);
}
