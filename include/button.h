/*
** EPITECH PROJECT, 2017
** button
** File description:
** button
*/

#ifndef BUTTON_
#define BUTTON_

#include "menu.h"
#include "map.h"

typedef struct button_s {
	sfTexture *idle;
	sfTexture *hover;
	sfTexture *clicked;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2u size;
	void (*ptr)(map_t *);
	void (*ptr_menu)(map_t *, menu_t *);
	sfText *text;
}button_t;

#endif
