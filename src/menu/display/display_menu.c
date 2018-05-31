/*
** EPITECH PROJECT, 2017
** display_menu
** File description:
** display_menu
*/

#include "window.h"
#include "menu.h"

void	display_button_menu(menu_t *menu, window_t *window)
{
	for (unsigned int i = 0; i != menu->nb_button; i++) {
		if (menu->button[i].sprite != NULL)
			display_state_button(window, &menu->button[i]);
	}
}

void	display_menu(window_t *window, menu_t *menu)
{

	sfRenderWindow_clear(window->window, sfBlue);
	display_button_menu(menu, window);
        sfRenderWindow_display(window->window);
}
