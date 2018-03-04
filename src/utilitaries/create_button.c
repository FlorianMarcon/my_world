/*
** EPITECH PROJECT, 2017
** create_button
** File description:
** create_button
*/

#include "header_world.h"
#include <stdlib.h>

const init_t but[10] = {
	{"./picture/larger.png", larger},
	{"./picture/smaller.png", smaller},
	{"./picture/rotate_r.png", rotate_l},
	{"./picture/rotate_l.png", rotate_r},
	{"./picture/incli_up.png", rotate_u},
	{"./picture/incli_down.png", rotate_d},
	{"./picture/up.png", up},
	{"./picture/down.png", down},
	{"./picture/erase.png", erase},
	{NULL, larger}
};

game_object_t	*create_object(const char *path_to_spritesheet, sfVector2f pos,
								sfIntRect rect)
{
	game_object_t	*elem = malloc(sizeof(*elem) * 1);

	elem->texture_obj = sfTexture_createFromFile(path_to_spritesheet, NULL);
	elem->sprite_obj = sfSprite_create();
	elem->rect_obj.top = rect.top;
	elem->rect_obj.left = rect.left;
	elem->rect_obj.width = rect.width;
	elem->rect_obj.height = rect.height;
	elem->pos.x = pos.x;
	elem->pos.y = pos.y;
	sfSprite_setPosition(elem->sprite_obj, pos);
	return (elem);
}

button_t	*button_init(sfVector2f position, sfVector2f size,
			void (*callback)(map_t *map), game_object_t *rooms)
{
	button_t *button = malloc(sizeof(*button));

	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setTexture(button->rect, rooms->texture_obj, sfTrue);
	sfRectangleShape_setTextureRect(button->rect, rooms->rect_obj);
	sfRectangleShape_setSize(button->rect, size);
	button->callback = callback;
	return (button);
}

button_t	**create_button(void)
{
	button_t **elem = malloc(sizeof(*elem) * 10);
	game_object_t *rooms;
	sfIntRect rect = set_rectangle(0, 0, 100, 100);
	sfVector2f pos = {10, 200};

	for (short i = 0; i != 6; i++, pos.y += 100) {
		rooms = create_object(but[i].path, (sfVector2f){0, 0}, rect);
		elem[i] = button_init(pos, (sfVector2f){100, 100},
							but[i].callback, rooms);
	}
	pos.x = 600;
	pos.y = 20;
	for (short i = 6; i != 9; i++, pos.x += 100) {
		rooms = create_object(but[i].path, (sfVector2f){0, 0}, rect);
		elem[i] = button_init(pos, (sfVector2f){100, 100},
							but[i].callback, rooms);
	}
	elem[9] = NULL;
	return (elem);
}
