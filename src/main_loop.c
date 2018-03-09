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
	button_t **elem = create_button();

	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		sfRenderWindow_clear(win->window, sfBlack);
		analyse_event(win, elem);
		display(win);
		sfRenderWindow_display(win->window);
		if (map->open == 0)
			sfRenderWindow_close(win->window);
	}
	sfRenderWindow_destroy(win->window);
	return (0);
}
