/*
** EPITECH PROJECT, 2017
** create_window
** File description:
** create_window
*/

#include "world.h"

int	create_window(window_t *window)
{
	window->mode = (sfVideoMode){1200, 800, 32};
	window->window = sfRenderWindow_create(window->mode, "SFML window", sfResize | sfClose, NULL);
	if (!window->window)
		return (1);
	return (0);
}
