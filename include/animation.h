/*
** animation.h for animation in /home/parejo_p/rush/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 14:34:08 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 22:45:13 2014 nicolas svirchevsky
*/

#ifndef		ANIMATION_H_
# define	ANIMATION_H_
# include	"parser.h"

typedef struct s_character	t_character;

typedef struct	s_animation
{
  t_map		*map;
  t_display	*display;
  SDL_Event	event;
  Uint8		*keystates;
}		t_animation;

void	animation_jump_left(t_character *self, t_animation *anim, int);
void	animation_jump_right(t_character *self, t_animation *anim, int);
void	animation_jump(t_character *self, t_animation *anim, int);
void	animation_right(t_character *self, t_animation *anim);
void	animation_left(t_character *self, t_animation *anim);
void	animation_up(t_character *self, t_animation *anim);
void	animation_down(t_character *self, t_animation *anim);
int	animation_monster(t_character *self, t_animation *anim);
int	animation_player(t_character *self, t_animation *anim);
int	animation(t_map *map, t_display *display, t_character *players);
int	is_grounded(t_character *self, t_animation *anim);
void	fall(t_character *self, t_animation *anim);

#endif		/* !ANIMATION_H_ */
