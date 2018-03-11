/*
** EPITECH PROJECT, 2018
** event
** File description:
** event
*/

#include "header_world.h"
#include <stdio.h>

int	button_click(button_t *button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->rect).x +
	sfRectangleShape_getSize(button->rect).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->rect).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->rect).y +
	sfRectangleShape_getSize(button->rect).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->rect).y);
}

char *my_calloc(char *line, int bufSize)
{
	line = malloc(sizeof(char) * bufSize);
	if (line == NULL)
		return (NULL);
	for (int i = 0; i < bufSize; i++)
		line[i] = 0;
	return (line);
}

void	analyse_event(surface_t *win, button_t **elem, file_t *file_name)
{
	sfVector2i clickPosition_one;
	sfVector2f clickPosition;

	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		clickPosition_one = sfMouse_getPosition((const sfWindow *)
								win->window);
		clickPosition.x = clickPosition_one.x;
		clickPosition.y = clickPosition_one.y;
		if (win->event.type == sfEvtTextEntered)
			print_file(win, file_name);
		if (win->event.type == sfEvtMouseButtonPressed) {
			if (button_click(elem[1], clickPosition)) {
				file_name->str[file_name->counter + 1] = '\0';
				elem[1]->callback(file_name->str);
				file_name->counter = 0;
				file_name->str = NULL;
				file_name->str = my_calloc(file_name->str, sizeof(char) * 20);
			}
			if (button_click(elem[0], clickPosition))
				elem[0]->callback(file_name->str);
		}
	}

}
