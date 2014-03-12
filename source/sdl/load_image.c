/*
** load_image.c<2> for  in /home/svirch_n/game
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sat Mar  8 11:08:28 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:39:38 2014 lefebv_z
*/

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<SDL/SDL_rotozoom.h>
#include	"my_sdl.h"

static SDL_Surface	*my_resize(SDL_Surface *image)
{
  SDL_Surface		*result;
  double		x;
  double		y;

  x = image->h;
  y = image->w;
  x =  BLOCKSIZE / x;
  y =  BLOCKSIZE / y;
  result = zoomSurface(image, y, x, SMOOTHING_ON);
  SDL_FreeSurface(image);
  return (result);
}

extern SDL_Surface	*load_image(const char *filename)
{
  SDL_Surface		*loaded_image;
  SDL_Surface		*optimized_image;
  Uint32		colorkey;

  if ((loaded_image = IMG_Load(filename)) == NULL)
    {
      printf("SDL: Could not load Image\n");
      return (NULL);
    }
  optimized_image = loaded_image;
  optimized_image = my_resize(optimized_image);

  colorkey = SDL_MapRGB(optimized_image->format, 0x00, 0x00, 0x00);
  SDL_SetColorKey(optimized_image,				\
		  SDL_RLEACCEL | SDL_SRCCOLORKEY , colorkey);
  return (optimized_image);
}
