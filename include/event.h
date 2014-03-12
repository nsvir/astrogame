/*
** event.h for event in /home/parejo_p/rush/T2Rush1/etape_2
** 
** Made by Pelayo Parejo Pagador
** Login   <parejo_p@epitech.net>
** 
** Started on  Sun Mar  9 12:54:31 2014 Pelayo Parejo Pagador
** Last update Sun Mar  9 23:07:05 2014 nicolas svirchevsky
*/

#ifndef		EVENT_H_
# define	EVENT_H_
# include	"animation.h"
# include	"my_sdl.h"

int		event_handler(t_character *, t_animation *);
int		jcdt(int type, t_animation *anim, t_character *self);

#endif		/* !EVENT_H_ */
