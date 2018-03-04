/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "header_world.h"
int	draw_water(sfRenderWindow *window, map_t *map);

int	display(surface_t *win, map_t *map, states_t *matter)
{
	draw_background(map, win);
	draw_water(win->window, map);
	draw_bottom_map(win->window, map, matter);
	draw_2d_map(win->window, map, matter);
	//draw_square_selection();
	evolve_two_d_map(map);
	return (0);
}
