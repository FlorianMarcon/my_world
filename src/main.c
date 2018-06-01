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

int	main(void)
{
	map_t map = {.is_usable = true};
	window_t window;
	world_t world = {.window = &window, .map = &map};

	if (create_world(&world))
		return (84);
	//loop_menu(&window);
	loop_game(&world);
	return (0);
}
