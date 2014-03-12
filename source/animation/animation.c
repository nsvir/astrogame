/*
** animation.c for animation in /home/parejo_p/rush/T2Rush1/etape_2/source/animation
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 13:34:04 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 22:17:57 2014 nicolas svirchevsky
*/

#include	<SDL/SDL.h>
#include	"animation.h"
#include	"my_sdl.h"
#include	"event.h"
#include	"free.h"

int	animation(t_map *map, t_display *display, t_character *players)
{
  t_animation	anim;
  t_character	*tmp;

  tmp = players;
  anim.map = map;
  anim.display = display;
  anim.keystates = SDL_GetKeyState(NULL);
  SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);
  while (43)
    {
      if (tmp->animate(tmp, &anim) == 1)
	return (my_exit(map, display));
      if (tmp->next == NULL)
	tmp = players;
      else
	tmp = tmp->next;
    }
}
