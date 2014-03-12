/*
** parser_check.c for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 22:01:14 2014 nicolas svirchevsky
** Last update Sat Mar  8 22:17:53 2014 nicolas svirchevsky
*/

#include	"my_sdl.h"
#include	"parser.h"

int		parser_check(t_map *map)
{
  int		i;
  int		j;
  int		end;

  i = 0;
  end = 0;
  while (i < map->line)
    {
      j = 0;
      while (j < map->column)
	{
	  if (map->map[i][j] == 'i')
	    {
	      if (end == 1)
		{
		  printf("Parser: multiple start door\n");
		  return (FAILURE);
		}
	      end = 1;
	    }
	  j++;
	}
      i++;
    }
  return (SUCCESS);
}
