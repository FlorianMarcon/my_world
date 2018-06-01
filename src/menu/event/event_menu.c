/*
** EPITECH PROJECT, 2017
** event_menu
** File description:
** event_menu
*/

#include "window.h"
#include "menu.h"

void	event_button_menu(window_t *window, menu_t *menu)
{
	for (unsigned int i = 0; i != menu->nb_button; i++) {
		if (sfMouse_isButtonPressed(sfMouseLeft) && is_about(window->window, &menu->button[i]) && menu->button[i].ptr != NULL) {
			menu->button[i].ptr(menu->map);
		}
	}
}
void	event_menu(window_t *window, menu_t *menu)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtKeyPressed) {
			event_textbox(menu, window);
		}
		event_button_menu(window, menu);
	}
}
