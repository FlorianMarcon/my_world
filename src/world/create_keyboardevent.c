/*
** EPITECH PROJECT, 2017
** create_keyboardevent
** File description:
** create_keyboardevent
*/


#include "world.h"
#include "map.h"
#include "window.h"

void	create_keyboardevent(world_t *world)
{
	world->nb_keyboardevent = 1;
	world->keyboardevent[0].key = sfKeyUp;
	world->keyboardevent[0].ptr = up_action;
}
