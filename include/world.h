/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#ifndef WORLD_
#define WORLD_

#include <SFML/Graphics.h>
#include "window.h"
#include "map.h"

typedef struct keyboardevent_s {
	sfKeyCode key;
	void (*ptr)(map_t *);
}keyboardevent_t;

typedef struct button_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2u size;
	void (*ptr)(map_t *);
}button_t;

typedef struct world_s {
	// window
	window_t *window;

	//map
	map_t *map;

	//button
	button_t button[5];
	unsigned int nb_button;

	//keyboard
	keyboardevent_t keyboardevent[2];
	unsigned int nb_keyboardevent;
}world_t;

int	create_world(world_t *world);

void	loop_game(world_t *world);

//event
void	event(world_t *world);

//display
void	display(world_t *world);

void	display_world(world_t *world);

//button
int	is_about(sfRenderWindow *renderwindow, button_t *button);

//keyboard

#endif
