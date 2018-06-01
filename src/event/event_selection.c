/*
** EPITECH PROJECT, 2017
** event_selection
** File description:
** event_selection
*/

#include <stdio.h>
#include "world.h"
#include "map.h"

int	is_here_negatif(sfVector2i *pos, sfVector2f **map, int x, int y)
{
	if (pos->x < map[y][x].x || pos->x > map[y + 1][x + 1].x)
		return (0);
	if (pos->y < map[y][x + 1].y || pos->y > map[y + 1][x].y)
		return (0);
	return(1);
}
int	is_here_positif(sfVector2i *pos, sfVector2f **map, int x, int y)
{
	if (pos->x < map[y + 1][x].x || pos->x > map[y][x + 1].x)
		return (0);
	if (pos->y < map[y][x].y || pos->y > map[y + 1][x + 1].y)
		return (0);
	return(1);
}
sfVector2i	search_position_selectioned_square(world_t *world)
{
	sfVector2i pos = sfMouse_getPosition((sfWindow *)world->window->window);
	map_t *map = world->map;

	for (unsigned int y = 0; y != map->height - 2; y++) {
		for (unsigned int x = 0; x != map->width - 2; x++)  {
			if (map->rotation < 0 && is_here_negatif(&pos, map->graph_map, x, y)) {
				pos.x = x;
				pos.y = y;
				return (pos);
			} else if (is_here_positif(&pos, map->graph_map, x, y)) {
				pos.x = x;
				pos.y = y;
				return (pos);
			}
		}
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
sfVector2i	search_position_selectioned_summit(world_t *world)
{
	sfVector2i pos = sfMouse_getPosition((sfWindow *)world->window->window);
	sfVector2f **map = world->map->graph_map;

	for (unsigned int y = 0; y != world->map->height - 2; y++) {
		for (unsigned int x = 0; x != world->map->width - 2; x++)  {
			if ((pos.x > map[y][x].x - 30 && pos.x < map[y][x].x + 30) &&
			(pos.y > map[y][x].y - 30 && pos.y < map[y][x].y + 30)) {
				pos.x = x;
				pos.y = y;
				return (pos);
			}
		}
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
void	event_selection(world_t *world)
{
	sfVector2i new = {-1, -1};

	if (world->done == true)
		return;
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		if (world->map->type_select == square) {
			new = search_position_selectioned_square(world);
		} else
			new = search_position_selectioned_summit(world);
	}
	if (new.x != -1 && new.y != -1) {
		world->map->x = new.x;
		world->map->y = new.y;
	}
}
