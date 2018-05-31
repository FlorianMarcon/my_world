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

typedef struct world_s {
	// window
	window_t *window;
	//map
	map_t *map;
}world_t;

int	create_world(world_t *world);

void	loop_game(world_t *world);

void	event(world_t *world);

void	display(world_t *world);

#endif
