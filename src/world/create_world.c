/*
** EPITECH PROJECT, 2017
** create_world
** File description:
** create_world
*/

#include "world.h"
#include "map.h"
#include "window.h"
#include <stdio.h>

void	set_background_world(world_t *world)
{
	char path[] = "./picture/background.jpg";

	world->spr_back = sfSprite_create();
	if (world->spr_back != NULL) {
		if ((world->tex_back = sfTexture_createFromFile(path, NULL)) == NULL)
			fprintf(stderr, "NULL\n");
		sfSprite_setTexture(world->spr_back, world->tex_back, sfTrue);
	}
}
int	create_world(world_t *world)
{
	if (world->map->is_usable == false || create_window(world->window))
		return (1);
	world->font = sfFont_createFromFile("font/font.otf");
	create_button(world);
	create_keyboardevent(world);
	set_background_world(world);
	return (0);
}
