/*
** my_sdl.h for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 23:29:25 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:29:25 2014 nicolas svirchevsky
*/

#ifndef			MY_SDL_H_
# define		MY_SDL_H_

# include		<SDL/SDL.h>
# include		"parser.h"
# include		"display.h"
# include		"macro.h"
# include		"animation.h"

enum
  {
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8,
    JUMP = 16,
    FALL = 32,
    NONE = 0
  };

typedef struct		s_character
{
  int			wait;
  int			status;
  int			bck;
  int			gravity;
  SDL_Surface		*current;
  int			current_pos;
  double		pos_x;
  double		pos_y;
  int			is_enemy;
  int			(*animate)(struct s_character *, t_animation *);
  struct s_character	*next;
}			t_character;

int			load_types(enum e_type *);
int			load_enemy(SDL_Surface **);
int			load_player(SDL_Surface **);
SDL_Surface		*load_image(const char*);
void			apply_surface(int, int, SDL_Surface*, SDL_Surface*);
int			load_sprites(SDL_Surface *sprites_tab[256]);
int			show_map(t_map *, SDL_Surface *, SDL_Surface **,
				 t_character*);
int			init_window(SDL_Surface **screen, int w, int h);

#endif			/* !MY_SDL_H_ */
