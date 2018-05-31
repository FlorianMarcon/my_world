/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#ifndef WINDOW_
#define WINDOW_

#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct window_s {
	sfRenderWindow *window;
	sfVideoMode mode;
	sfEvent event;
}window_t;

int	create_window(window_t *window);

#endif
