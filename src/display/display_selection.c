/*
** EPITECH PROJECT, 2017
** display_selection
** File description:
** display_selection
*/

#include "map.h"
#include "window.h"
#include "world.h"

sfVertexArray	*set_vertex_array_line(sfVector2f *one, sfVector2f *two)
{
	sfVertexArray *vertex_array = sfVertexArray_create();

	if (vertex_array == NULL)
		return (NULL);
	sfVertex vertex1 = {.position = *one, .color = sfRed};
	sfVertex vertex2 = {.position = *two, .color = sfRed};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}
void	display_selection_summit(map_t *map)
{
	sfVertexArray **vertex = map->vertex_mouse;
	unsigned int i = 0;
	sfVector2f center = map->graph_map[map->y][map->x];

	if (map->x != 0)
		vertex[i++] = set_vertex_array_line(&center,
					&map->graph_map[map->y][map->x - 1]);
	if (map->x != map->width - 2)
		vertex[i++] = set_vertex_array_line(&center,
					&map->graph_map[map->y][map->x + 1]);
	if (map->y != 0)
		vertex[i++] = set_vertex_array_line(&center,
					&map->graph_map[map->y - 1][map->x]);
	if (map->y != map->height - 2)
		vertex[i++] = set_vertex_array_line(&center,
					&map->graph_map[map->y + 1][map->x]);
	vertex[i] = NULL;
}
void	display_selection_square(map_t *map)
{
	sfVertexArray **vertex = map->vertex_mouse;

	vertex[0] = set_vertex_array_line(&map->graph_map[map->y][map->x],
					&map->graph_map[map->y][map->x + 1]);
	vertex[2] = set_vertex_array_line(&map->graph_map[map->y][map->x],
					&map->graph_map[map->y + 1][map->x]);
	vertex[1] = set_vertex_array_line(&map->graph_map[map->y + 1]
			[map->x + 1], &map->graph_map[map->y][map->x + 1]);
	vertex[3] = set_vertex_array_line(&map->graph_map[map->y + 1]
			[map->x + 1], &map->graph_map[map->y + 1][map->x]);
	vertex[4] = NULL;
}
void	display_selection(world_t *world)
{
	map_t *map = world->map;
	window_t *window = world->window;

	for (unsigned int i = 0; map->vertex_mouse[i] != NULL; i++)
		sfVertexArray_destroy(map->vertex_mouse[i]);
	if (map->type_select == summit)
		display_selection_summit(map);
	else
		display_selection_square(map);
	for (unsigned int i = 0; map->vertex_mouse[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(window->window,
						map->vertex_mouse[i], NULL);
}
