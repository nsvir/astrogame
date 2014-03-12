/*
** parser_file.c for  in /home/svirch_n/game/pel/T2Rush1/etape_1
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 18:29:09 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:39:53 2014 lefebv_z
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		"my_sdl.h"
#include		"parser.h"

static int		int_parser_error(const char *str)
{
  printf("Parser: %s\n", str);
  return (FAILURE);
}

static void		*parser_error(const char *str)
{
  printf("Parser: %s\n", str);
  return (NULL);
}

static void		*create_list(char *buff, size_t size,	\
				     t_list **tmp, t_list **begin)
{
  t_list		*list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return (parser_error("Could not malloc"));
  list->data = buff;
  list->size = size;
  list->next = NULL;
  if (*tmp)
    (*tmp)->next = list;
  else
    (*begin) = list;
  return (list);
}

static void		*get_content(FILE *fd, int *i)
{
  size_t		none;
  int			size;
  char			*buff;
  t_list		*list;
  t_list		*begin;
  t_list		*tmp;

  none = 0;
  buff = NULL;
  tmp = NULL;
  while ((size = getline(&buff, &none, fd)) > 0)
    {
      if (buff[size - 1] == '\n')
	buff[size-- - 1] = 0;
      if ((list = create_list(buff, size, &tmp, &begin)) == NULL)
	return (NULL);
      if (tmp && list->size != tmp->size)
	return (parser_error("Invalid line length"));
      tmp = list;
      buff = NULL;
      (*i)++;
    }
  return (begin);
}

int			parser_file(const char *filename, t_map *map)
{
  FILE			*fd;
  int			i;
  t_list		*begin;

  i = 0;
  if ((fd = fopen(filename, "r")) == NULL)
    return (int_parser_error("Could not open"));
  if ((begin = get_content(fd, &i)) == NULL)
    return (FAILURE);
  map->line = i;
  if ((map->map = malloc(sizeof(char*) * i)) == NULL)
    return (int_parser_error("Could not malloc"));
  map->column = begin->size;
  i = 0;
  while (begin)
    {
      map->map[i] = begin->data;
      begin = begin->next;
      i++;
    }
  return (SUCCESS);
}
