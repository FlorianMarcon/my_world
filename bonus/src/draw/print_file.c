/*
** EPITECH PROJECT, 2017
** draw_background
** File description:
** draw_background
*/

#include "header_world.h"

void print_file(surface_t *win, file_t *file_name)
{
	sfText_setPosition(file_name->text, file_name->pos);
	if (win->event.text.unicode != 13 && win->event.text.unicode != 8) {
		if (file_name->counter < 20) {
			file_name->str[file_name->counter] = win->event.text.unicode;
			file_name->counter++;
		}
	} else if (win->event.text.unicode == 8) {
		if (file_name->counter > 0) {
			file_name->counter --;
			file_name->str[file_name->counter] = ' ';
			sfText_setString(file_name->text, file_name->str);
			sfRenderWindow_clear(win->window, sfBlack);
			sfRenderWindow_drawText(win->window, file_name->text, NULL);
		}
	}
	sfText_setString(file_name->text, file_name->str);
}
