/*
** EPITECH PROJECT, 2017
** draw_square_selection
** File description:
** draw_square_selection
*/

#include "header_world.h"

int	draw_square_selection(sfRenderWindow *window, sfVector2f **map_two_d,
								int x, int y)
{
	sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[y][x], map_two_d[y][x + 1], sfRed), NULL);
	sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[y][x], map_two_d[y + 1][x], sfRed), NULL);
	sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[y][x + 1], map_two_d[y + 1][x + 1], sfRed), NULL);
	sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[y + 1][x], map_two_d[y + 1][x + 1], sfRed), NULL);
	return (1);
}
