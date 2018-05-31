/*
** EPITECH PROJECT, 2017
** menu
** File description:
** menu
*/

#ifndef MENU_
#define MENU_

#include "window.h"
#include "world.h"

typedef struct menu_s {
	unsigned int width;
	unsigned int height;

	unsigned int nb_button;
	button_t button[3];

	sfFont *font;
}menu_t;

void	loop_menu(window_t *window);

void	display_menu(window_t *window, menu_t *menu);

void	event_menu(window_t *window);

void	create_menu(menu_t *menu);

#endif
