/*
** load_sprites.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 13:49:00 2014 nicolas svirchevsky
** Last update Wed Mar 12 00:06:45 2014 nicolas svirchevsky
*/

#include		"my_sdl.h"

int		load_enemy(SDL_Surface **enemy)
{
  int		i;
  char		*buf;

  if (!(buf = strdup("./sprites/Enemies/slime_walk/slime_walk0X.png\0")))
    return (FAILURE);
  i = 0;
  while (i < 8)
    {
      buf[40] = (char)(i + '0');
      if ((enemy[i] = load_image(buf)) == NULL)
	return (FAILURE);
      i++;
    }
  free(buf);
  return (SUCCESS);
}

int		load_player(SDL_Surface **players)
{
  int		i;
  char		*buf;

  if (!(buf = strdup("./sprites/Player/p1_walk/walk/p1_walk0X.png\0")))
    return (FAILURE);
  i = 0;
  while (i < 8)
    {
      buf[38] = (char)(i + '0');
      if ((players[i] = load_image(buf)) == NULL)
	return (FAILURE);
      i++;
    }
  free(buf);
  return (SUCCESS);
}


int			load_sprites(SDL_Surface *sprites_tab[256])
{
  unsigned char		i;

  i = 0;
  while (i < 255)
    {
      sprites_tab[i] = NULL;
      i++;
    }
  if (!(sprites_tab['w'] = load_image("./sprites/Tiles/grassCenter.png"))
      || !(sprites_tab['!'] = load_image("./sprites/Tiles/ladder_top.png"))
      || !(sprites_tab['('] = load_image("./sprites/Tiles/grassCliffLeft.png"))
      || !(sprites_tab[')'] = load_image("./sprites/Tiles/grassCliffRight.png"))
      || !(sprites_tab['f'] = load_image("./sprites/Tiles/grassMid.png"))
      || !(sprites_tab['s'] = load_image("./sprites/Tiles/ladder_mid.png"))
      || !(sprites_tab['k'] = load_image("./sprites/Items/keyRed.png"))
      || !(sprites_tab['o'] = load_image("./sprites/Tiles/window.png"))
      || !(sprites_tab['v'] = load_image("./sprites/Items/plant.png"))
      || !(sprites_tab['b'] = load_image("./sprites/Tiles/bridgeLogs.png"))
      || !(sprites_tab['i'] =
	   load_image("./sprites/Items/buttonRed_pressed.png")))
    return (FAILURE);
  return (SUCCESS);
}
