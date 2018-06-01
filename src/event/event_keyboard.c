/*
** EPITECH PROJECT, 2017
** event_keyboard
** File description:
** event_keyboard
*/

#include "world.h"
#include <stdio.h>

void	event_keyboard(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_keyboardevent; i++) {
		if (sfKeyboard_isKeyPressed(world->keyboardevent[i].key) && world->keyboardevent[i].ptr != NULL)
			world->keyboardevent[i].ptr(world->map);
		fprintf(stderr, "%i\n", i);
	}

}
