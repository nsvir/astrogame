/*
** parser.h for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 19:33:11 2014 nicolas svirchevsky
** Last update Sun Mar  9 14:34:27 2014 nicolas svirchevsky
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<SDL/SDL.h>
# include	"display.h"

typedef	struct
{
  int		line;
  int		column;
  char		**map;
}		t_map;

typedef struct s_list
{
  int		size;
  void		*data;
  struct s_list	*next;
}		t_list;

int		parser_file(const char *filename, t_map *map);
void		*parser_create(t_map *map, t_display *);
int		parser_check(t_map *map);
void		*get_player(t_map *map, SDL_Surface **);
void		*pcerror(const char *str);

#endif		/* !PARSER_H_ */
