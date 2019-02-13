/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "map.h"
#include "window.h"
#include "world.h"
#include "menu.h"
#include "my.h"

int	set_all_game(int ac, char **av, world_t *world)
{
	if (ac > 2) {
		my_printf("Usage: ./my_rpg [optional map.legend]\n");
		return (1);
	} else if (ac == 2) {
		load_map(world->map, av[1]);
		if (create_world(world))
			return (1);
	} else {
		if (create_world(world))
			return (1);
		loop_menu(world->window, world->map);
	}
	return (0);
}
int	main(int ac, char **av)
{
	map_t map = {.is_usable = true, .width = 20, .height = 20};
	window_t window;
	world_t world = {.window = &window, .map = &map};

	if (set_all_game(ac, av, &world))
		return (84);
	loop_game(&world);
	return (0);
}
