/*
** EPITECH PROJECT, 2017
** create_button
** File description:
** create_button
*/

#include "world.h"
#include "map.h"

void	set_button(button_t *but, sfVector2f position, void *ptr)
{
	but->sprite = sfSprite_create();
	but->position = position;
	if (but->sprite != NULL)
		sfSprite_setPosition(but->sprite, but->position);
	but->ptr = ptr;
	but->text = NULL;
	but->idle = NULL;
	but->hover = NULL;
	but->clicked = NULL;
}
void	set_helptextbox(button_t *but, sfFont *font, char *msg)
{
	but->text = sfText_create();
	sfText_setString(but->text, msg);
	sfText_setFont(but->text, font);
}
void	set_button_texture(button_t *but, char *idle, char *hover, char *click)
{
	if (idle != NULL)
		but->idle = sfTexture_createFromFile(idle, NULL);
	if (but->idle != NULL) {
		but->size = sfTexture_getSize(but->idle);
		sfSprite_setTexture(but->sprite, but->idle, sfTrue);
	} else
		but->size = (sfVector2u){0, 0};
	if (hover != NULL && click != NULL) {
		but->hover = sfTexture_createFromFile(hover, NULL);
		but->clicked = sfTexture_createFromFile(click, NULL);
	}
}
void	create_button(world_t *world)
{
	world->nb_button = 1;
	set_button(&world->button[0], (sfVector2f){0, 0}, &up_action);
	set_helptextbox(&world->button[0], world->font, "Up tool");
	set_button_texture(&world->button[0], "./picture/smaller_idle.png", "./picture/smaller_hover.png", "./picture/smaller_clicked.png");

	//set_button(&world->button[1], "./picture/down.png", (sfVector2f){0,70}, NULL);
	//set_button(&world->button[2], "./picture/larger.png", (sfVector2f){0, 140}, &up_action);
	//set_button(&world->button[3], "./picture/smaller.png", (sfVector2f){0,210}, NULL);
}
