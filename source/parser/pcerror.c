/*
** pcerror.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 12:43:26 2014 nicolas svirchevsky
** Last update Sun Mar  9 12:43:48 2014 nicolas svirchevsky
*/

#include	"parser.h"
#include	<stdio.h>

void		*pcerror(const char *str)
{
  printf("Parser: %s\n", str);
  return (NULL);
}
