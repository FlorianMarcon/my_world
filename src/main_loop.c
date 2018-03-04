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
int	main_loop(void)
{
	surface_t *win = init_window();
	map_t *map = create_matrice_map(20, 10);
	states_t *matter = create_list_texture();
	sfEvent event2;
	button_t button_larger;
	button_t button_smaller;
	button_t button_rotate_right;
	button_t button_rotate_left;
	button_t button_up;
	button_t button_down;
	button_t *elem[6];
	int num_buttons = 6;
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
		//event(win, map);
		sfRenderWindow_clear(win->window, sfBlack);
		display(win, map, matter);
		analyse_event(win->window, event2, *elem, num_buttons, map);
		for (int j = 0; j < num_buttons; j++)
			sfRenderWindow_drawRectangleShape(win->window, elem[j]->rect, NULL);
		sfRenderWindow_display(win->window);
		if (map->open == 0)
			sfRenderWindow_close(win->window);
	}
	save_map(map);
	sfRenderWindow_destroy(win->window);
	return (0);
}
