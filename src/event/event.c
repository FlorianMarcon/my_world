/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "world.h"

void	event_button(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (sfMouse_isButtonPressed(sfMouseLeft) && is_about(world->window->window, &world->button[i]) && world->button[i].ptr != NULL)
			world->button[i].ptr(world->map);
	}
}
void	event_keyboard(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (sfKeyboard_isKeyPressed(world->keyboardevent[i].key) && world->keyboardevent[i].ptr != NULL)
			world->keyboardevent[i].ptr(world->map);
	}

}
void	event_window(world_t *world)
{
	window_t *window = world->window;

	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		event_button(world);
		event_keyboard(world);
	}
}
void	event(world_t *world)
{
	event_window(world);
}
