/*
** EPITECH PROJECT, 2017
** mouse event
** File description:
** mouse event
*/

#include <stdio.h>
#include "header_world.h"

int	is_here(sfVector2i *pos, map_t *mapp, int x, int y)
{
	int a = 0;
	sfVector2f **map = mapp->map_two_d;

	if ((pos->x >= map[y][x].x && pos->x <= map[y][x + 1].x)
	|| (pos->x >= map[y + 1][x].x && pos->x <= map[y + 1][x + 1].x)) {
		a++;
	}
	if ((pos->y >= map[y][x].y && pos->y <= map[y + 1][x].y)) {
		a++;
	}
	switch (a) {
		case 2: return (1);
		default: return (0);
	}
}
int	selection_square_mouse(sfVector2i *pos, map_t *map)
{
	int y = 0;
	int x = 0;

	while (y != map->height - 1) {
		x = 0;
		while (x != map->width) {
			if (is_here(pos, map, x, y) == 1) {
				map->x = x;
				map->y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
int	mouse_event(surface_t *win, map_t *map)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);

	selection_square_mouse(&pos, map);
	return (1);
}
