/*
** EPITECH PROJECT, 2017
** create_button
** File description:
** create_button
*/

#include "header_world.h"
#include <stdlib.h>

const init_t but[3] = {
	{"./picture/background.jpg", name1},
	{"./picture/background.jpg", compile},
	{NULL, compile}
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
			void (*callback)(), game_object_t *rooms)
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
	button_t **elem = malloc(sizeof(*elem) * 3);
	game_object_t *rooms;
	sfIntRect rect = set_rectangle(0, 0, 100, 100);
	sfVector2f pos = {700, 650};

	rooms = create_object(but[0].path, (sfVector2f){0, 0}, rect);
	elem[0] = button_init(pos, (sfVector2f){400, 60},
						but[0].callback, rooms);
	pos.y = 800;
	pos.x = 835;
	rooms = create_object(but[1].path, (sfVector2f){0, 0}, rect);
	elem[1] = button_init(pos, (sfVector2f){100, 100},
						but[1].callback, rooms);
	elem[2] = NULL;
	return (elem);
}
