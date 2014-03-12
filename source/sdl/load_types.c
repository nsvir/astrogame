/*
** load_types.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 15:54:12 2014 nicolas svirchevsky
** Last update Sun Mar  9 18:36:59 2014 nicolas svirchevsky
*/

#include	"my_sdl.h"
#include	"parser.h"

int		load_types(enum e_type type[256])
{
  unsigned char	i;

  i = 0;
  while (i < 255)
    type[i++] = EMPTY;
  type['w'] = BLOCK;
  type['('] = BLOCK;
  type[')'] = BLOCK;
  type['f'] = BLOCK;
  type['!'] = LADDER;
  type['s'] = LADDER;
  type['k'] = ITEM;
  type['o'] = END_DOOR;
  type['i'] = START_DOOR;
  type['v'] = DECOR;
  type['b'] = BLOCK;
  return (SUCCESS);
}
