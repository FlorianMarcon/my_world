/*
** EPITECH PROJECT, 2017
** create_world
** File description:
** create_world
*/

#include "world.h"
#include "map.h"
#include "window.h"
#include <stdio.h>

void	set_button(button_t *but, char *path, sfVector2f position, void *ptr)
{
	but->sprite = sfSprite_create();
	but->texture = sfTexture_createFromFile(path, NULL);
	but->position = position;
	if (but->sprite != NULL && but->texture != NULL) {
		sfSprite_setTexture(but->sprite, but->texture, sfFalse);
		sfSprite_setPosition(but->sprite, but->position);
		but->size = sfTexture_getSize(but->texture);
	}
	but->ptr = ptr;
}
void	create_button(world_t *world)
{
	world->nb_button = 4;
	set_button(&world->button[0], "./picture/up.png", (sfVector2f){0, 0}, &up_action);
	set_button(&world->button[1], "./picture/down.png", (sfVector2f){0,70}, NULL);
	set_button(&world->button[2], "./picture/larger.png", (sfVector2f){0, 140}, &up_action);
	set_button(&world->button[3], "./picture/smaller.png", (sfVector2f){0,210}, NULL);
}
void	create_keyboardevent(world_t *world)
{
	world->nb_keyboardevent = 1;
	world->keyboardevent[0].key = sfKeyUp;
	world->keyboardevent[0].ptr = up_action;

}
int	create_world(world_t *world)
{
	create_map(world->map, 10, 10);
	if (world->map->is_usable == false || create_window(world->window))
		return (1);
	create_button(world);
	create_keyboardevent(world);
	return (0);
}
