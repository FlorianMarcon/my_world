/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** .c
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdlib.h>
#include <math.h>

#define MAP_X 6
#define MAP_Y 6
#define SCALING_X 124
#define SCALING_Y 124
#define SCALING_Z 14

void close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_display(window);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfBlack};
	sfVertex vertex2 = {.position = *point2, .color = sfBlack};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVertexArray *create_quad(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfVector2f *point4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite, .texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = *point2, .color = sfGreen, .texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = *point3, .color = sfBlack, .texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = *point4, .color = sfYellow, .texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **map_two_d, sfRenderStates earth_states)
{
	int j = 0;
	int i = 0;

	while (j < 6) {
		while (i < 6) {
			if (i + 1 < 6 && j + 1 < 6)
				sfRenderWindow_drawVertexArray(window,
				create_quad(&map_two_d[j][i], &map_two_d[j][i + 1], &map_two_d[j + 1][i + 1], &map_two_d[j + 1][i]), &earth_states);
			/*if (i + 1 < 6)
				sfRenderWindow_drawVertexArray(window,
				create_line(&map_two_d[j][i], &map_two_d[j][i + 1]), NULL);
			if (j + 1 < 6)
				sfRenderWindow_drawVertexArray(window,
				create_line(&map_two_d[j][i], &map_two_d[j + 1][i]), NULL);*/
				i++;
		}
		i = 0;
		j++;
	}
	sfRenderWindow_display(window);
	return (0);
}

sfVector2f project_iso_point(int x, int y, int z)
{
	sfVector2f two_d_point;
	double angle1 = 65 * M_PI / 180;
	double angle2 = 10 * M_PI / 180;

	two_d_point.x = cos(angle1) * x - cos(angle1) * y + 350;
	two_d_point.y = sin(angle2) * y + sin(angle2) * x - z + 250;

	return (two_d_point);
}

sfVector2f **create_two_d_map(int **map_three_d)
{
	sfVector2f **map_two_d = malloc(sizeof(sfVector2f*) * 6);
	int i = 0;
	int j = 0;

	while (j < 6) {
		map_two_d[j] = malloc(sizeof(sfVector2f) * 6);
		while (i < 6) {
			map_two_d[j][i] = project_iso_point(i * SCALING_X, j * SCALING_Y, map_three_d[j][i] * SCALING_Z);
			i++;
		}
		i = 0;
		j++;
	}
	return (map_two_d);
}


int main(void)
{
	sfRenderWindow *window;
	sfVideoMode video_mode;
	sfEvent event;
	int **map = malloc(sizeof(int *) * MAP_Y);
	int i = 0;
	int j = 0;
	sfRenderStates earth_states;

	while (j < 6) {
		map[j] = malloc(sizeof(int) * MAP_X);
		while (i < 6) {
			map[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
	map[2][3] = 8;
	map[3][2] = 1;
	map[2][4] = 12;
	sfVector2f **map_two_d = create_two_d_map(map);

	video_mode.width = 800;
	video_mode.height = 600;
	video_mode.bitsPerPixel = 32;

	earth_states.blendMode = sfBlendNone;
	earth_states.texture = sfTexture_createFromFile("earth.jpg", NULL);
	earth_states.transform = sfTransform_Identity;
	earth_states.shader = NULL;

	window = sfRenderWindow_create(video_mode, "my_world", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				close_window(window);
		}
	draw_2d_map(window, map_two_d, earth_states);
	}
	sfRenderWindow_destroy(window);
	return (0);
}