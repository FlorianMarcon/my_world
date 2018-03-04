/*
** EPITECH PROJECT, 2017
** create_matter
** File description:
** create_matter
*/

#include <stdlib.h>
#include "material.h"
#include "header_world.h"

states_t	*create_list_texture(void)
{
	states_t *text = malloc(sizeof(*text) * SIZE_MATTER);
	int i = 0;

	while (i != SIZE_MATTER - 1) {
		text[i].matter = mat[i].matter;
		text[i].states.blendMode = sfBlendNone;
		text[i].states.texture = sfTexture_createFromFile
							(mat[i].path, NULL);
		text[i].states.transform = sfTransform_Identity;
		text[i].states.shader = NULL;
		i++;
	}
	text[i].matter = null;
	return (text);
}
