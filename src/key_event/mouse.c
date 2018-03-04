/*
** EPITECH PROJECT, 2017
** mouse event
** File description:
** mouse event
*/

#include <stdio.h>
#include "header_world.h"

int	is_here(sfVector2i *pos, sfVector2f **map, int x, int y)
{
	int a = 0;

	if (pos->x >= map[y][x].x && pos->x <= map[y][x + 1].x) {
		a++;
	}
	if (pos->y >= map[y][x].y && pos->y <= map[y + 1][x].y) {
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
	sfVector2f **map_two_d = map->map_two_d;

	while (y != map->height) {
		x = 0;
		while (x != map->width) {
//			printf("x = %i, y = \n", );
			if (is_here(pos, map_two_d, x, y) == 1) {
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
