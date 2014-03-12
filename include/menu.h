/*
** menu.h for rush in /home/marie/modules/unix/rush/T2Rush1/etape_2
** 
** Made by lefebv_z
** Login   <marie@epitech.net>
** 
** Started on  Sat Mar  8 22:47:31 2014 lefebv_z
** Last update Sun Mar  9 17:49:56 2014 lefebv_z
*/

#ifndef		MENU_H_
# define	MENU_H_

# include	<SDL/SDL.h>
#include	"parser.h"

/* #define	MARGIN		50 */
# define	MENU_W			1800
# define	MENU_H			900
# define	WELCOME			"Bienvenue dans Epikong !"
# define	PR_W(screen_w)		(screen_w / 3)
# define	PR_H(screen_h)		(screen_h / 2)
# define	PR_X(i, screen_w)	((screen_w / 3) * ((i + 1) % 3))
# define	PR_Y(i, screen_h)	(((i + 1) < 3) ? (0) : (screen_h / 2))

int		menu(SDL_Surface *screen, SDL_Surface **sprites,	\
		     t_map **map);
int		render_menu(SDL_Surface *screen, SDL_Surface **images);

#endif		/* !MENU_H_ */
