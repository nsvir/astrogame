/*
** apply_surface.c for  in /home/svirch_n/game
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 12:37:39 2014 nicolas svirchevsky
** Last update Sun Mar  9 14:10:56 2014 nicolas svirchevsky
*/

#include	<SDL/SDL.h>

void		apply_surface(int x, int y, SDL_Surface *src,	\
			      SDL_Surface *dest)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dest, &offset);
}
