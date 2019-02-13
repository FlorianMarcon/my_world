/*
** EPITECH PROJECT, 2017
** create_list_floor
** File description:
** create_list_floor
*/

#include <stdio.h>
#include "floor.h"

void	set_floor(floor_t *floor, char *texture, int id, type_floor_t type)
{
	floor->state.blendMode = sfBlendAlpha;
	floor->state.texture = sfTexture_createFromFile(texture, NULL);
	floor->state.transform = sfTransform_Identity;
	floor->state.shader = NULL;
	floor->id = id;
	floor->type = type;
}
void	create_list_floor(floor_t *floor)
{
	set_floor(&floor[0], "./picture/grass.png", 0, GRASS);
	set_floor(&floor[1], "./picture/water.jpg", 1, WATER);
	set_floor(&floor[2], "./picture/dirt.png", 2, DIRT);
}
