/*
** EPITECH PROJECT, 2017
** create_button
** File description:
** create_button
*/

#include "world.h"
#include "map.h"

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
	but->text = NULL;
}
void	set_helptextbox(button_t *but, sfFont *font, char *msg)
{
	but->text = sfText_create();
	sfText_setString(but->text, msg);
	sfText_setFont(but->text, font);
}
void	create_button(world_t *world)
{
	world->nb_button = 4;
	set_button(&world->button[0], "./picture/up.png", (sfVector2f){0, 0}, &up_action);
	set_helptextbox(&world->button[0], world->font, "Up tool");
	set_button(&world->button[1], "./picture/down.png", (sfVector2f){0,70}, NULL);
	set_button(&world->button[2], "./picture/larger.png", (sfVector2f){0, 140}, &up_action);
	set_button(&world->button[3], "./picture/smaller.png", (sfVector2f){0,210}, NULL);
}
