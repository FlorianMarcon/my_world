/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "header_world.h"

int	display(surface_t *win, map_t *map, states_t *matter)
{
	evolve_two_d_map(map);
	draw_background(map, win);
	draw_bottom_map(win->window, map, matter);
	draw_2d_map(win->window, map, matter);
	//draw_square_selection();
	return (0);
}
