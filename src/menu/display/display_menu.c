/*
** EPITECH PROJECT, 2017
** display_menu
** File description:
** display_menu
*/

#include "window.h"
#include "menu.h"
#include <stdio.h>

void	display_button_menu(menu_t *menu, window_t *window)
{
	for (unsigned int i = 0; i != menu->nb_button; i++) {
		if (menu->button[i].sprite != NULL)
			display_state_button(window, &menu->button[i]);
	}
}

void	display_textbox(window_t *window, menu_t *menu)
{
	sfText *text;
	char *str;

	for (unsigned int i = 0; i != menu->nb_textbox; i++) {
		str = menu->textbox[i].str;
		text = menu->textbox[i].text;
		sfText_setString(text, str);
		sfRenderWindow_drawText(window->window, text, NULL);
	}
}
void	display_menu(window_t *window, menu_t *menu)
{
	sfRenderWindow_clear(window->window, sfBlue);
	sfRenderWindow_drawSprite(window->window, menu->spr_back, NULL);
	display_button_menu(menu, window);
	display_textbox(window, menu);
        sfRenderWindow_display(window->window);
}
