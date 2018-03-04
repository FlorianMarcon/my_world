/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef WORLD_
#define WORLD_

#define MAP_X 30
#define MAP_Y 30
#define SCALING_X 110
#define SCALING_Y 110
#define SCALING_Z 10
#define ANGLE_X 65
#define ANGLE_Y 10

// structure pour la window

typedef struct surface_s {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
}surface_t;

// struct for map

typedef struct map {
	int **map;
	int width;
	int height;
	int x_center;
	int y_center;
	int scaling_x;
	int scaling_y;
	sfVector2f **map_two_d;

	// selectioned position
	int x;
	int y;

	float zoom;
	int rotation;
	int inclinaison;
}map_t;

typedef enum matter {
	earth,
	water,
	grass,
	null,
}matter_t;

//

typedef struct states_s {
	matter_t matter;
	sfRenderStates states;
	sfVector2i shape;
} states_t;

// fonction de création

typedef struct for_create_state_s {
	matter_t matter;
	char *path;
}for_create_state_t;

states_t	*create_list_texture(void);
map_t	*create_matrice_map(int height, int width);
sfVector2f	project_iso_point(int x, int y, map_t *map);
void	create_two_d_map(map_t *map);
void	evolve_two_d_map(map_t *map);

// draw_2d_map

int	draw_2d_map(sfRenderWindow *window, map_t *map, states_t *tex);
sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4);
sfVertexArray *create_line(sfVector2f point1, sfVector2f point2, sfColor color);

// loop principale

int	main_loop(void);

int	event(surface_t *win, map_t *map);

#endif
