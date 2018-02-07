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

#define MAP_X 30
#define MAP_Y 30
#define SCALING_X 110
#define SCALING_Y 110
#define SCALING_Z 10

typedef struct states_s {
	sfRenderStates states;
	sfVector2i shape;
} states_t;

void close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_display(window);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, sfColor color)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = color};
	sfVertex vertex2 = {.position = *point2, .color = color};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVertexArray *create_quad(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfVector2f *point4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite, .texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite, .texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = *point3, .color = sfWhite, .texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = *point4, .color = sfWhite, .texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **map_two_d, states_t **states, int **map)
{
	int text = 2;
	int color = 2;

	for (int j = 0; j < MAP_X; j++) {
		for (int i = 0; i < MAP_Y; i++) {
			/*if (i + 1 < MAP_X)
				sfRenderWindow_drawVertexArray(window, create_line(&map_two_d[j][i], &map_two_d[j][i + 1], sfBlack), NULL);
			if (j + 1 < MAP_Y)
				sfRenderWindow_drawVertexArray(window, create_line(&map_two_d[j][i], &map_two_d[j + 1][i], sfBlack), NULL);*/
			if (i + 1 < MAP_X && j + 1 < MAP_Y) {
				if (map[j][i + 1] < 0)
					text = 1;
				else if (map[j][i + 1] > 0)
					text = 0;
				else
					text = 2;
				if (i > 0 && j > 0)
					sfRenderWindow_drawVertexArray(window,create_quad(&map_two_d[j - 1][i], &map_two_d[j - 1][i + 1], &map_two_d[j][i + 1], &map_two_d[j][i]), &states[text]->states);
				sfRenderWindow_drawVertexArray(window,create_quad(&map_two_d[j][i], &map_two_d[j][i + 1], &map_two_d[j + 1][i + 1], &map_two_d[j + 1][i]), &states[text]->states);
				sfRenderWindow_drawVertexArray(window,create_line(&map_two_d[states[color]->shape.x][states[color]->shape.y], &map_two_d[states[color]->shape.x][states[color]->shape.y + 1], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(&map_two_d[states[color]->shape.x][states[color]->shape.y + 1], &map_two_d[states[color]->shape.x][states[color]->shape.y + 2], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(&map_two_d[states[color]->shape.x][states[color]->shape.y + 1], &map_two_d[states[color]->shape.x + 1][states[color]->shape.y + 1], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(&map_two_d[states[color]->shape.x - 1][states[color]->shape.y + 1], &map_two_d[states[color]->shape.x][states[color]->shape.y + 1], sfRed), NULL);
			}
		}
	}
	//sfRenderWindow_drawVertexArray(window,
	//create_quad(&map_two_d[shape->x][shape->y], &map_two_d[shape->x][shape->y + 2], &map_two_d[sha_pe->x + 2][shape->y + 2], &map_two_d[shape->x + 2][shape->y]), NULL);
	sfRenderWindow_display(window);
	return (0);
}

sfVector2f project_iso_point(int x, int y, int z)
{
	sfVector2f two_d_point;
	double angle1 = 65 * M_PI / 180;
	double angle2 = 10 * M_PI / 180;

	two_d_point.x = cos(angle1) * x - cos(angle1) * y + 950;
	two_d_point.y = sin(angle2) * y + sin(angle2) * x - z + 150;

	return (two_d_point);
}

sfVector2f **create_two_d_map(int **map_three_d)
{
	sfVector2f **map_two_d = malloc(sizeof(sfVector2f*) * MAP_X);
	int i = 0;
	int j = 0;

	while (j < MAP_Y) {
		map_two_d[j] = malloc(sizeof(sfVector2f) * MAP_X);
		while (i < MAP_X) {
			map_two_d[j][i] = project_iso_point(i * SCALING_X, j * SCALING_Y, map_three_d[j][i] * SCALING_Z);
			i++;
		}
		i = 0;
		j++;
	}
	return (map_two_d);
}

states_t *create_texture(states_t *states, char *s)
{
	states->states.blendMode = sfBlendNone;
	states->states.texture = sfTexture_createFromFile(s, NULL);
	states->states.transform = sfTransform_Identity;
	states->states.shader = NULL;
	states->shape.x = 1;
	states->shape.y = 0;
	return(states);
}

int **analyse_events(sfRenderWindow *window, sfEvent event, states_t **states, int **map)
{
	int color = 2;
	//sfMouseButtonEvent mouse;
	while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				close_window(window);
			if (event.type == sfEvtKeyPressed) {
				if (event.key.code == sfKeyP)
					map[states[color]->shape.x][states[color]->shape.y + 1]++;
				if (event.key.code == sfKeyO) {
					map[states[color]->shape.x][states[color]->shape.y + 1]++;
					map[states[color]->shape.x - 1][states[color]->shape.y]++;
					map[states[color]->shape.x - 1][states[color]->shape.y + 2]++;
					map[states[color]->shape.x + 1][states[color]->shape.y]++;
					map[states[color]->shape.x + 1][states[color]->shape.y + 2]++;
					map[states[color]->shape.x][states[color]->shape.y]++;
					map[states[color]->shape.x][states[color]->shape.y + 2]++;
					map[states[color]->shape.x - 1][states[color]->shape.y + 1]++;
					map[states[color]->shape.x + 1][states[color]->shape.y + 1]++;
				}
				if (event.key.code == sfKeyI) {
					map[states[color]->shape.x][states[color]->shape.y + 1]+=2;
					map[states[color]->shape.x - 1][states[color]->shape.y]++;
					map[states[color]->shape.x - 1][states[color]->shape.y + 2]++;
					map[states[color]->shape.x + 1][states[color]->shape.y]++;
					map[states[color]->shape.x + 1][states[color]->shape.y + 2]++;
					map[states[color]->shape.x][states[color]->shape.y]++;
					map[states[color]->shape.x][states[color]->shape.y + 2]++;
					map[states[color]->shape.x - 1][states[color]->shape.y + 1]++;
					map[states[color]->shape.x + 1][states[color]->shape.y + 1]++;
				}
				if (event.key.code == sfKeyM)
					map[states[color]->shape.x][states[color]->shape.y + 1]--;
				if (event.key.code == sfKeyL) {
					map[states[color]->shape.x][states[color]->shape.y + 1]--;
					map[states[color]->shape.x - 1][states[color]->shape.y]--;
					map[states[color]->shape.x - 1][states[color]->shape.y + 2]--;
					map[states[color]->shape.x + 1][states[color]->shape.y]--;
					map[states[color]->shape.x + 1][states[color]->shape.y + 2]--;
					map[states[color]->shape.x][states[color]->shape.y]--;
					map[states[color]->shape.x][states[color]->shape.y + 2]--;
					map[states[color]->shape.x - 1][states[color]->shape.y + 1]--;
					map[states[color]->shape.x + 1][states[color]->shape.y + 1]--;
				}
				if (event.key.code == sfKeyK) {
					map[states[color]->shape.x][states[color]->shape.y + 1]-=2;
					map[states[color]->shape.x - 1][states[color]->shape.y]--;
					map[states[color]->shape.x - 1][states[color]->shape.y + 2]--;
					map[states[color]->shape.x + 1][states[color]->shape.y]--;
					map[states[color]->shape.x + 1][states[color]->shape.y + 2]--;
					map[states[color]->shape.x][states[color]->shape.y]--;
					map[states[color]->shape.x][states[color]->shape.y + 2]--;
					map[states[color]->shape.x - 1][states[color]->shape.y + 1]--;
					map[states[color]->shape.x + 1][states[color]->shape.y + 1]--;
				}
				if (event.key.code == sfKeySpace)
					map[states[color]->shape.x][states[color]->shape.y + 1] = 0;
				if (event.key.code == sfKeyN) {
					map[states[color]->shape.x][states[color]->shape.y + 1] = 0;
					map[states[color]->shape.x - 1][states[color]->shape.y] = 0;
					map[states[color]->shape.x - 1][states[color]->shape.y + 2] = 0;
					map[states[color]->shape.x + 1][states[color]->shape.y] = 0;
					map[states[color]->shape.x + 1][states[color]->shape.y + 2] = 0;
					map[states[color]->shape.x][states[color]->shape.y] = 0;
					map[states[color]->shape.x][states[color]->shape.y + 2] = 0;
					map[states[color]->shape.x - 1][states[color]->shape.y + 1] = 0;
					map[states[color]->shape.x + 1][states[color]->shape.y + 1] = 0;
				}
				if (event.key.code == sfKeyUp && states[color]->shape.x > 1)
					states[color]->shape.x --;
				if (event.key.code == sfKeyDown && states[color]->shape.x < MAP_X - 2)
					states[color]->shape.x ++;
				if (event.key.code == sfKeyLeft && states[color]->shape.y > 0)
					states[color]->shape.y --;
				if (event.key.code == sfKeyRight && states[color]->shape.y < MAP_Y - 3)
					states[color]->shape.y ++;
				sfRenderWindow_clear(window, sfBlue);
			}
		}
		return (map);
}

int main(void)
{
	sfRenderWindow *window;
	sfVideoMode video_mode;
	sfEvent event;
	sfVector2i pos_mouse;

	states_t *states[3];
	states_t earth_states;
	states_t water_states;
	states_t grass_states;

	sfVector2f **map_two_d;
	int **map = malloc(sizeof(int *) * MAP_Y);
	int i = 0;
	int j = 0;

	while (j < MAP_X) {
		map[j] = malloc(sizeof(int) * MAP_X);
		while (i < MAP_Y) {
			map[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}

	video_mode.width = 2300;
	video_mode.height = 2300;
	video_mode.bitsPerPixel = 32;

	states[0] = create_texture(&earth_states, "dirt.png");
	states[1] = create_texture(&water_states, "water.jpg");
	states[2] = create_texture(&grass_states, "grass.png");

	window = sfRenderWindow_create(video_mode, "my_world", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlue),
		map = analyse_events(window, event, states, map);
		map_two_d = create_two_d_map(map);
		pos_mouse = sfMouse_getPosition((sfWindow *)window);
		draw_2d_map(window, map_two_d, states, map);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
