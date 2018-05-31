/*
** EPITECH PROJECT, 2017
** loop_menu
** File description:
** loop_menu
*/

#include "menu.h"
#include "window.h"

void	loop_menu(window_t *window)
{
	menu_t menu;

	create_menu(&menu);
	while (sfRenderWindow_isOpen(window->window)) {
		event_menu(window);
		display_menu(window, &menu);
	}
}
