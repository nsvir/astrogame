/*
** animation_sprite.c for  in /home/svirch_n/depot/T2Rush1/etape_2
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Mar  9 23:29:10 2014 nicolas svirchevsky
** Last update Sun Mar  9 23:29:11 2014 nicolas svirchevsky
*/

#include	"my_sdl.h"
#include	"animation.h"

void	animation_up(t_character *self, t_animation *anim)
{
  self->status |= UP;
  self->pos_y -= BLOCKSIZE / 4.0;
  if (self->current_pos == 3)
    self->current_pos = 4;
  if (self->current_pos == 7)
    self->current_pos = 4;
  else
    self->current_pos++;
  if (self->wait == 0)
    self->wait = 3;
  else if (self->wait == 1)
    self->status ^= UP;
  if (self->is_enemy)
    self->current = anim->display->enemy[self->current_pos];
  else
    self->current = anim->display->player[self->current_pos];
}

void	animation_down(t_character *self, t_animation *anim)
{
  self->status |= DOWN;
  self->pos_y += BLOCKSIZE / 4.0;
  if (self->current_pos == 3)
    self->current_pos = 4;
  if (self->current_pos == 7)
    self->current_pos = 4;
  else
    self->current_pos++;
  if (self->wait == 0)
    self->wait = 3;
  else if (self->wait == 1)
    self->status ^= DOWN;
  if (self->is_enemy)
    self->current = anim->display->enemy[self->current_pos];
  else
    self->current = anim->display->player[self->current_pos];
}

void	animation_right(t_character *self, t_animation *anim)
{
  self->status |= RIGHT;
  self->pos_x += BLOCKSIZE / 4.0;
  if (self->current_pos == 3)
    self->current_pos = 4;
  if (self->current_pos == 7)
    self->current_pos = 4;
  else
    self->current_pos++;
  if (self->wait == 0)
    self->wait = 3;
  else if (self->wait == 1)
    self->status ^= RIGHT;
  if (self->is_enemy)
    self->current = anim->display->enemy[self->current_pos];
  else
    self->current = anim->display->player[self->current_pos];
}

void	animation_left(t_character *self, t_animation *anim)
{
  self->status |= LEFT;
  self->pos_x -= BLOCKSIZE / 4.0;
  if (self->current_pos == 4)
    self->current_pos = 3;
  if (self->current_pos == 0)
    self->current_pos = 3;
  else
    self->current_pos--;
  if (self->wait == 0)
    self->wait = 3;
  else if (self->wait == 1)
    self->status ^= LEFT;
  if (self->is_enemy)
    self->current = anim->display->enemy[self->current_pos];
  else
    self->current = anim->display->player[self->current_pos];
}
