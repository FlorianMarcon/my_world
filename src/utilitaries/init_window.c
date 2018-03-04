/*
** EPITECH PROJECT, 2017
**
** File description:
**
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
