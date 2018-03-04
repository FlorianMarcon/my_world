/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>
int	draw_bottom_map(sfRenderWindow *window, map_t *map, states_t *tex);

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
	void (*callback)(int *);
} button_t;

typedef	struct game_object_s {
	sfSprite *sprite_obj;
	sfTexture *texture_obj;
	sfVector2f pos;
	sfIntRect rect_obj;
} game_object_t;

void	kitchen(int *boolean)
{
	*boolean = 1;
}

void	restaurant(int *boolean)
{
	*boolean = 0;
}

void	outsidem(int *boolean)
{
	*boolean = 2;
}

void	exitgame(int *boolean)
{
	*boolean = 3;
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


void	analyse_event(sfRenderWindow *window, sfEvent event2, button_t *restaurant, int num_rep, int *boolean)
{
	sfVector2i clickPosition_one;
	sfVector2f clickPosition;

	while (sfRenderWindow_pollEvent(window, &event2)) {
		if (event2.type == sfEvtClosed || *boolean == 3)
			sfRenderWindow_close(window);
		if (event2.type == sfEvtMouseButtonPressed) {
			clickPosition_one = sfMouse_getPosition((const sfWindow *)window);
			clickPosition.x = clickPosition_one.x;
			clickPosition.y = clickPosition_one.y;
			for (int i = 0; i < num_rep; i++) {
				if (*boolean == 0) {
					if (buttonIsClicked(restaurant[i], clickPosition))
						restaurant[i].callback(boolean);
				} else if (*boolean == 1) {
					if (buttonIsClicked(restaurant[i], clickPosition))
						restaurant[i].callback(boolean);
				} else if (*boolean == 2) {
					if (buttonIsClicked(restaurant[i], clickPosition))
						restaurant[i].callback(boolean);
				}
			}
		}
	}
}

button_t	*buttonInitialise(button_t *button, sfVector2f position, sfVector2f size, void (*callback)(int *boolean), game_object_t *rooms)
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

int	main_loop()
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(20, 10);
	states_t *matter = create_list_texture();
	sfEvent event2;
	button_t button_scene1_scne2;
	button_t button_exitgame;
	button_t button_pause_game;
	button_t *elem[6];
	int num_buttons = 6;
	int boolean = 0;
	game_object_t *rooms[3];
	sfIntRect rect_larger;
	sfIntRect rect_smaller;
	sfIntRect rect_return;

	rect_larger = set_rectangle(rect_larger, 0,0,100,100);
	rooms[0] = create_object("./picture/larger.png", (sfVector2f){-250, -300}, rect_larger);
	rect_smaller = set_rectangle(rect_smaller, 0,0,100,100);
	rooms[1] = create_object("./picture/smaller.png", (sfVector2f){-250, -300}, rect_smaller);
	rect_return = set_rectangle(rect_return, 0,0,100,100);
	rooms[2] = create_object("./picture/return.png", (sfVector2f){-250, -300}, rect_return);
	elem[0] = buttonInitialise(&button_scene1_scne2, (sfVector2f){30, 10}, (sfVector2f){100, 100}, kitchen, rooms[0]);
	elem[1] = buttonInitialise(&button_exitgame, (sfVector2f){30, 250}, (sfVector2f){100, 100}, exitgame, rooms[1]);
	elem[2] = buttonInitialise(&button_pause_game, (sfVector2f){30, 450}, (sfVector2f){100, 100}, outsidem, rooms[2]);
	if (win == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 60);
	while (sfRenderWindow_isOpen(win->window)) {
		event(win, map);
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		analyse_event(win->window, event2, *elem, 3, &boolean);
		for (int j = 0; j < num_buttons; j++)
			sfRenderWindow_drawRectangleShape(win->window, elem[j]->rect, NULL);
		sfRenderWindow_display(win->window);
	}
	sfRenderWindow_destroy(win->window);
	return (0);
}
