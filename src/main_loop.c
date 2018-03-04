/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>

int	mouse_event(surface_t *win, map_t *map);
int	draw_bottom_map(sfRenderWindow *window, map_t *map, states_t *tex);
void	save_map(map_t *map);

surface_t	*init_window(void)
{
	surface_t *win = malloc(sizeof(*win));

	if (win == NULL)
		return (NULL);
	win->mode.width = 1600;
	win->mode.height = 1200;
	win->mode.bitsPerPixel = 32;
	win->window = sfRenderWindow_create(win->mode, "SFML window",\
						sfResize | sfClose, NULL);
	if (!win->window)
		return (NULL);
	return (win);
}

int	display(surface_t *win, map_t *map, states_t *matter)
{
	evolve_two_d_map(map);
	draw_background(map, win);
	draw_bottom_map(win->window, map, matter);
	draw_2d_map(win->window, map, matter);
	//draw_square_selection();
	return (0);
}

typedef	struct scene_s {
	struct game_object_s *objs;
	struct button_s *buttons[3];
} scene_t;

typedef	struct button_s {
	sfRectangleShape *rect;
	void (*callback)(map_t *);
} button_t;

typedef	struct game_object_s {
	sfSprite *sprite_obj;
	sfTexture *texture_obj;
	sfVector2f pos;
	sfIntRect rect_obj;
} game_object_t;

void	larger(map_t *map)
{
	map->zoom += 0.80;
}

void	smaller(map_t *map)
{
	map->zoom -= 0.80;
}

void	rotate_l(map_t *map)
{
	map->rotation += 4;
}

void	rotate_r(map_t *map)
{
	map->rotation -= 4;
}
void	rotate_u(map_t *map)
{
	map->inclinaison += 4;
}

void	rotate_d(map_t *map)
{
	map->inclinaison -= 4;
}


int	buttonIsClicked(button_t button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button.rect).x +
	sfRectangleShape_getSize(button.rect).x &&
	clickPosition.x > sfRectangleShape_getPosition(button.rect).x &&
	clickPosition.y < sfRectangleShape_getPosition(button.rect).y +
	sfRectangleShape_getSize(button.rect).y &&
	clickPosition.y > sfRectangleShape_getPosition(button.rect).y);
}

game_object_t	*create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
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
	return(elem);
}


void	analyse_event(surface_t *win, button_t *elem, map_t *map)
{
	sfVector2i clickPosition_one;
	sfVector2f clickPosition;

	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		clickPosition_one = sfMouse_getPosition((const sfWindow *)win->window);
		clickPosition.x = clickPosition_one.x;
		clickPosition.y = clickPosition_one.y;
		if (win->event.type == sfEvtMouseButtonPressed) {
			for (int i = 0; i < 6; i++) {
				if (buttonIsClicked(elem[i], clickPosition))
					elem[i].callback(map);
			}
		}
		//if (sfMouse_isButtonPressed(sfMouseLeft))
			mouse_event(win, map);
		if (sfKeyboard_isKeyPressed(sfKeyRight))
			map->transla_x += 1;
		if (sfKeyboard_isKeyPressed(sfKeyLeft))
			map->transla_x -= 1;
		if (sfKeyboard_isKeyPressed(sfKeyUp))
			map->transla_y -= 1;
		if (sfKeyboard_isKeyPressed(sfKeyDown))
			map->transla_y += 1;
	}
}

button_t	*buttonInitialise(button_t *button, sfVector2f position, sfVector2f size, void (*callback)(map_t *map), game_object_t *rooms)
{
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setTexture(button->rect, rooms->texture_obj, sfTrue);
	sfRectangleShape_setTextureRect(button->rect, rooms->rect_obj);
	sfRectangleShape_setSize(button->rect, size);
	button->callback = callback;
	return (button);
}

sfIntRect	set_rectangle(sfIntRect rect, int top, int left, int width, int height)
{
	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

int	main_loop(void)
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(20, 10);
	states_t *matter = create_list_texture();
	sfVector2i clickPosition_one;
	button_t *elem[6];
	button_t button_larger;
	button_t button_smaller;
	button_t button_rotate_right;
	button_t button_rotate_left;
	button_t button_up;
	button_t button_down;
	game_object_t *rooms[6];
	sfIntRect rect_larger;
	sfIntRect rect_smaller;
	sfIntRect rect_rotate_right;
	sfIntRect rect_rotate_left;
	sfIntRect rect_up;
	sfIntRect rect_down;

	rect_larger = set_rectangle(rect_larger, 0,0,100,100);
	rooms[0] = create_object("./picture/larger.png", (sfVector2f){-250, -300}, rect_larger);
	rect_smaller = set_rectangle(rect_smaller, 0,0,100,100);
	rooms[1] = create_object("./picture/smaller.png", (sfVector2f){-250, -300}, rect_smaller);
	rect_rotate_right = set_rectangle(rect_rotate_right, 0,0,100,100);
	rooms[2] = create_object("./picture/return.png", (sfVector2f){-250, -300}, rect_rotate_right);
	rect_rotate_left = set_rectangle(rect_rotate_left, 0,0,100,100);
	rooms[3] = create_object("./picture/return.png", (sfVector2f){-250, -300}, rect_rotate_left);
	rect_up = set_rectangle(rect_up, 0,0,100,100);
	rooms[4] = create_object("./picture/return.png", (sfVector2f){-250, -300}, rect_up);
	rect_down = set_rectangle(rect_down, 0,0,100,100);
	rooms[5] = create_object("./picture/return.png", (sfVector2f){-250, -300}, rect_down);

	elem[0] = buttonInitialise(&button_larger, (sfVector2f){10, 200}, (sfVector2f){100, 100}, larger, rooms[0]);
	elem[1] = buttonInitialise(&button_smaller, (sfVector2f){10, 310}, (sfVector2f){100, 100}, smaller, rooms[1]);
	elem[2] = buttonInitialise(&button_rotate_right, (sfVector2f){10, 410}, (sfVector2f){100, 100}, rotate_l, rooms[2]);
	elem[3] = buttonInitialise(&button_rotate_left, (sfVector2f){10, 510}, (sfVector2f){100, 100}, rotate_r, rooms[3]);
	elem[4] = buttonInitialise(&button_up, (sfVector2f){10, 610}, (sfVector2f){100, 100}, rotate_u, rooms[4]);
	elem[5] = buttonInitialise(&button_down, (sfVector2f){10, 710}, (sfVector2f){100, 100}, rotate_d, rooms[5]);

	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		analyse_event(win, *elem, map);
		clickPosition_one = sfMouse_getPosition((const sfWindow *)win->window);
		if (clickPosition_one.x < 100 && (clickPosition_one.y > 200 && clickPosition_one.x < 710)) {
			for (int j = 0; j < 6; j++)
				sfRenderWindow_drawRectangleShape(win->window, elem[j]->rect, NULL);
		}
		sfRenderWindow_display(win->window);
		if (map->open == 0)
			sfRenderWindow_close(win->window);
	}
	save_map(map);
	sfRenderWindow_destroy(win->window);
	return (0);
}
