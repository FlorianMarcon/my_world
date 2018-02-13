/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"
#include <stdlib.h>

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
	sfVector2f **map_two_d;

	map_two_d = create_two_d_map(map->map);
	draw_2d_map(win->window, map_two_d, map, matter);
	return (0);
}
int	main_loop()
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(10, 10);
	states_t *matter = create_list_texture();

	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		while (sfRenderWindow_pollEvent(win->window, &win->event)) {
			if (win->event.type == sfEvtClosed)
				sfRenderWindow_close(win->window);
		}
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		sfRenderWindow_display(win->window);
	}
	sfRenderWindow_destroy(win->window);
	return (0);
}
