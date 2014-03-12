/*
** display.h for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 14:32:37 2014 nicolas svirchevsky
** Last update Sun Mar  9 18:38:30 2014 nicolas svirchevsky
*/

#ifndef		DISPLAY_H_
# define	DISPLAY_H_

# include	"macro.h"
# include	<SDL/SDL.h>

enum e_type
  {
    BLOCK,
    ITEM,
    LADDER,
    END_DOOR,
    START_DOOR,
    EMPTY,
    DECOR
  };

typedef	struct
{
  SDL_Surface		*screen;
  SDL_Surface		*sprites[256];
  enum e_type		type[256];
  SDL_Surface		*player[8];
  SDL_Surface		*enemy[8];
  char			map[LINE][COLUMN];
}			t_display;

#endif		/* !DISPLAY_H_ */
