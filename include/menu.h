/*
** EPITECH PROJECT, 2017
** menu
** File description:
** menu
*/

#ifndef MENU_
#define MENU_

#include <stdbool.h>
#include "window.h"
#include "world.h"
#include "map.h"

#define SIZE 20

typedef struct text_box_s {
	char str[SIZE];
	sfText *text;
	sfVector2f position;
	sfFont *font;
}text_box_t;

typedef struct menu_s {
	unsigned int width;
	unsigned int height;

	unsigned int nb_button;
	button_t button[3];

	sfFont *font;

	unsigned int nb_textbox;
	text_box_t textbox[5];

	sfSprite *spr_back;
	sfTexture *tex_back;

	map_t *map;
}menu_t;

void	loop_menu(window_t *window, map_t *map);

void	display_menu(window_t *window, menu_t *menu);

void	event_menu(window_t *window, menu_t *menu);

void	event_textbox(menu_t *menu, window_t *window);

void	create_menu(menu_t *menu);

//button
void	menu_create_map(map_t *map);

void	menu_load_map(map_t *map);

#endif
