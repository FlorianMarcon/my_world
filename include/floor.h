/*
** EPITECH PROJECT, 2017
** floor
** File description:
** floor
*/

#ifndef FLOOR_
#define FLOOR_

#include <SFML/Graphics.h>

typedef enum type_floor {
	WATER,
	GRASS,
	DIRT,
	NOTHING
}type_floor_t;

typedef struct floor_s {
	type_floor_t type;
	int id;

	sfRenderStates state;
}floor_t;

void	create_list_floor(floor_t *floor);

void	set_floor(floor_t *floor, char *texture, int id, type_floor_t type);

#endif
