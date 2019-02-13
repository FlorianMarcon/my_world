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
void	create_button_indexe(world_t *world)
{
	set_button(&world->button[4], (sfVector2f){1000, 0}, &select_summit);
	set_helptextbox(&world->button[4], world->font, "Selection summit");
	set_button_texture(&world->button[4], "./picture/summit_idle.png",
		"./picture/summit_hover.png", "./picture/summit_clicked.png");
	set_button(&world->button[5], (sfVector2f){1000, 60}, &select_square);
	set_helptextbox(&world->button[5], world->font, "Selection square");
	set_button_texture(&world->button[5], "./picture/floor_idle.png",
		"./picture/floor_hover.png", "./picture/summit_clicked.png");
	set_button(&world->button[6], (sfVector2f){1050, 120}, &save_map);
	set_helptextbox(&world->button[6], world->font, "Save your map");
	set_button_texture(&world->button[6], "./picture/save_idle.png",
		"./picture/save_hover.png", "./picture/save_clicked.png");
	set_button(&world->button[7], (sfVector2f){1050, 700}, &quit);
	set_helptextbox(&world->button[7], world->font, "QUIT the game");
	set_button_texture(&world->button[7], "./picture/quit_idle.png",
		"./picture/quit_hover.png", "./picture/quit_clicked.png");

}
void	create_button(world_t *world)
{
	world->nb_button = 8;
	set_button(&world->button[0], (sfVector2f){0, 20}, &up_action);
	set_helptextbox(&world->button[0], world->font, "Up tool");
	set_button_texture(&world->button[0], "./picture/up_idle.png",
			"./picture/up_hover.png", "./picture/up_clicked.png");
	set_button(&world->button[1], (sfVector2f){0, 120}, &down_action);
	set_helptextbox(&world->button[1], world->font, "Down tool");
	set_button_texture(&world->button[1], "./picture/down_idle.png",
		"./picture/down_hover.png", "./picture/down_clicked.png");
	set_button(&world->button[2], (sfVector2f){0, 240}, &zoom_in);
	set_helptextbox(&world->button[2], world->font, "Zoom in");
	set_button_texture(&world->button[2], "./picture/plus_idle.png",
	"./picture/plus_hover.png", "./picture/validated.png");
	set_button(&world->button[3], (sfVector2f){0, 360}, &zoom_out);
	set_helptextbox(&world->button[3], world->font, "Zoom out");
	set_button_texture(&world->button[3], "./picture/moins_idle.png",
		"./picture/moins_hover.png", "./picture/validated.png");
	create_button_indexe(world);
}
