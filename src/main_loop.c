/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>
int	draw_bottom_map(sfRenderWindow *window, map_t *map, states_t *tex);

surface_t	*init_window(void)
{
	surface_t *win = malloc(sizeof(*win));

	if (win == NULL)
		return (NULL);
	win->mode.width = 1600;
	win->mode.height = 1200;
	win->mode.bitsPerPixel = 32;
	win->window = sfRenderWindow_create(win->mode, "SFML window",\
						sfResize | sfClose, NULL);
	if (!win->window)
		return (NULL);
	return (win);
}

int	display(surface_t *win, map_t *map, states_t *matter)
{
	evolve_two_d_map(map);
	draw_background(map, win);
	draw_bottom_map(win->window, map, matter);
	draw_2d_map(win->window, map, matter);
	//draw_square_selection();
	return (0);
}
int	main_loop()
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(20, 10);
	states_t *matter = create_list_texture();

	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		event(win, map);
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		sfRenderWindow_display(win->window);
	}
	sfRenderWindow_destroy(win->window);
	return (0);
}
