/*
** EPITECH PROJECT, 2017
** display_button
** File description:
** display_button
*/

#include "world.h"

void	display_button_help_text(window_t *window, button_t *button)
{
	sfVector2i mouse = sfMouse_getPosition((sfWindow *)window->window);

	sfText_setPosition(button->text, (sfVector2f) {mouse.x, mouse.y});
	sfRenderWindow_drawText(window->window, button->text, NULL);
}
void	display_button(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (world->button[i].sprite != NULL)
			sfRenderWindow_drawSprite(world->window->window, world->button[i].sprite, NULL);
		if (is_about(world->window->window, &world->button[i]) && world->button[i].text != NULL)
			display_button_help_text(world->window, &world->button[i]);
	}
}
