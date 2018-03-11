/*
** EPITECH PROJECT, 2017
** draw_background
** File description:
** draw_background
*/

#include "header_world.h"

void my_drawSprite(surface_t *win, game_object_t *elem)
{
	sfSprite_setPosition(elem->sprite_obj, elem->pos);
	sfSprite_setTexture(elem->sprite_obj, elem->texture_obj, sfTrue);
	sfSprite_setTextureRect(elem->sprite_obj, elem->rect_obj);
	sfRenderWindow_drawSprite(win->window, elem->sprite_obj, NULL);
}
