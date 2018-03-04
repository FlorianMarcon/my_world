/*
** EPITECH PROJECT, 2017
** draw_background
** File description:
** draw_background
*/

#include "header_world.h"

int	draw_background(map_t *map, surface_t *win)
{
	sfRenderWindow_drawSprite(win->window, map->background, NULL);
	return (1);
}
