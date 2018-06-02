/*
** EPITECH PROJECT, 2017
** loop_menu
** File description:
** loop_menu
*/

#include "menu.h"
#include "window.h"
#include "my.h"

void	menu_create(menu_t *menu, map_t *map)
{
	if (my_strlen(menu->textbox[0].str) <= 0)
		return;
	if (my_str_isnum(menu->textbox[1].str) && my_str_isnum(menu->textbox[2].str)) {
		map->name = my_strdup(menu->textbox[0].str);
		map->do_exit = true;
		map->width = my_getnbr(menu->textbox[1].str);
		map->height = my_getnbr(menu->textbox[2].str);
		if (map->width < 10 || map->height < 10) {
			map->width = 10;
			map->height = 10;
		}
		create_map(map, map->width, map->height);
	}
}
void	menu_load(menu_t *menu, map_t *map)
{
	char *str = menu->textbox[0].str;

	str = my_strcat(str, ".legend");
	load_map(map, str);
	if (map->is_usable == true)
		map->do_exit = true;
}
void	treatement_map(menu_t *menu, map_t *map)
{
	if (map->create == true) {
		menu_create(menu, map);
		map->create = false;
	}
	if (map->load == true) {
		menu_load(menu, map);
		map->load = false;
	}
}
void	loop_menu(window_t *window, map_t *map)
{
	menu_t menu;

	map->do_exit = false;
	map->create = false;
	map->load = false;
	create_menu(&menu);
	menu.map = map;
	while (sfRenderWindow_isOpen(window->window) && map->do_exit != true) {
		event_menu(window, &menu);
		display_menu(window, &menu);
		treatement_map(&menu, map);
	}
}
