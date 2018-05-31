/*
** EPITECH PROJECT, 2017
** is_about
** File description:
** is_about
*/

#include "world.h"

int	is_about(sfRenderWindow *renderwindow, button_t *button)
{
	sfWindow *window = (sfWindow *)renderwindow;
	sfVector2i pos = sfMouse_getPosition(window);

	if (pos.x < button->position.x || pos.x > button->position.x + button->size.x)
		return (0);
	if (pos.y < button->position.y || pos.y > button->position.y + button->size.y)
		return (0);
	return (1);
}
