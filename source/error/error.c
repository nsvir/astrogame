/*
** error.c for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 18:35:31 2014 nicolas svirchevsky
** Last update Sat Mar  8 19:46:48 2014 nicolas svirchevsky
*/

#include	<SDL/SDL.h>
#include	<stdio.h>
#include	"my_sdl.h"

int		sdl_error(const char *error)
{
  printf("%s: %s\n", error, SDL_GetError());
  return (FAILURE);
}

int		my_error(const char *error)
{
  printf("%s\n", error);
  return (FAILURE);
}
