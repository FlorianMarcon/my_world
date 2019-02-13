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
	world->nb_keyboardevent = 8;
	world->keyboardevent[0].key = sfKeyUp;
	world->keyboardevent[0].ptr = inclinaison_down;
	world->keyboardevent[1].key = sfKeyDown;
	world->keyboardevent[1].ptr = inclinaison_up;
	world->keyboardevent[2].key = sfKeyRight;
	world->keyboardevent[2].ptr = rotation_right;
	world->keyboardevent[3].key = sfKeyLeft;
	world->keyboardevent[3].ptr = rotation_left;
	world->keyboardevent[4].key = sfKeyD;
	world->keyboardevent[4].ptr = translation_right;
	world->keyboardevent[5].key = sfKeyQ;
	world->keyboardevent[5].ptr = translation_left;
	world->keyboardevent[6].key = sfKeyZ;
	world->keyboardevent[6].ptr = translation_up;
	world->keyboardevent[7].key = sfKeyS;
	world->keyboardevent[7].ptr = translation_down;
}
