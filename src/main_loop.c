/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>

int	main_loop(int width, int height)
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(width, height);
	states_t *matter = create_list_texture();
	button_t **elem = create_button();

	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		draw_left_toolbar(win, elem);
		analyse_event(win, elem, map);
		sfRenderWindow_display(win->window);
		if (map->open == 0)
			sfRenderWindow_close(win->window);
	}
	save_map(map);
	sfRenderWindow_destroy(win->window);
	return (0);
}
