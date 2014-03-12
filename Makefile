##
## Makefile for  in /home/svirch_n/game
## 
## Made by nicolas svirchevsky
## Login   <svirch_n@epitech.net>
## 
## Started on  Sat Mar  8 10:19:45 2014 nicolas svirchevsky
## Last update Wed Mar 12 00:15:33 2014 nicolas svirchevsky
##

NAME		=	astrogame

SRC		=	./source/main.c				\
			./source/sdl/load_image.c		\
			./source/sdl/apply_surface.c		\
			./source/sdl/show_map.c			\
			./source/sdl/event_handler.c		\
			./source/sdl/load_sprites.c		\
			./source/sdl/jcdt.c			\
			./source/sdl/load_types.c		\
			./source/menu/menu.c			\
			./source/menu/render_menu.c		\
			./source/error/error.c			\
			./source/parser/parser_file.c		\
			./source/parser/parser_create.c		\
			./source/parser/get_player.c		\
			./source/parser/parser_check.c		\
			./source/parser/pcerror.c		\
			./source/animation/animation.c		\
			./source/animation/animation_monster.c	\
			./source/animation/animation_player.c	\
			./source/animation/animation_sprite.c	\
			./source/animation/animation_jump.c	\
			./source/animation/animation_fall.c	\
			./source/free/free.c

OBJ		=	$(SRC:.c=.o)

CC		=	/usr/bin/gcc

CFLAGS		=	-W -Wextra -Wall
CFLAGS		+=	-I ./include

LDFLAGS		=	-lSDL -lSDL_image -lSDL_gfx -lSDL_ttf

RM		=	rm -f

ECHO		=	echo -e

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIB) $(LDFLAGS)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean re
