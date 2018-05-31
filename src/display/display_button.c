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
void	display_state_button(window_t *window, button_t *button)
{
	if (is_about(window->window, button)) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			sfSprite_setTexture(button->sprite, button->clicked, sfTrue);
		else {
			display_button_help_text(window, button);
			sfSprite_setTexture(button->sprite, button->hover, sfTrue);
		}
	} else
		sfSprite_setTexture(button->sprite, button->idle, sfTrue);
	sfRenderWindow_drawSprite(window->window, button->sprite, NULL);
}
void	display_button(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (world->button[i].sprite != NULL)
			display_state_button(world->window, &world->button[i]);
	}
}
