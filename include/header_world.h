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

#define BACKGROUND "picture/background.jpg"
#define MEMORY "memory/memory"
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
	float scaling_x;
	float scaling_y;
	sfVector2f **map_two_d;

	// selectioned position
	int x;
	int y;

	float zoom;
	int rotation;
	int inclinaison;
	int transla_x;
	int transla_y;

	sfSprite *background;

	int open;
}map_t;

typedef enum matter {
	earth,
	water,
	grass,
	null,
	bottom,
}matter_t;

//

typedef struct states_s {
	matter_t matter;
	sfRenderStates states;
	sfVector2i shape;
} states_t;

// button

typedef	struct scene_s {
	struct game_object_s *objs;
	struct button_s *buttons[3];
} scene_t;

typedef struct init {
	char *path;
	void (*callback)(map_t *);
}init_t;

typedef	struct button_s {
	sfRectangleShape *rect;
	void (*callback)(map_t *);
} button_t;

typedef	struct game_object_s {
	sfSprite *sprite_obj;
	sfTexture *texture_obj;
	sfVector2f pos;
	sfIntRect rect_obj;
} game_object_t;

void	larger(map_t *map);

void	smaller(map_t *map);

void	rotate_l(map_t *map);

void	rotate_r(map_t *map);

void	rotate_u(map_t *map);

void	rotate_d(map_t *map);

void	up(map_t *map);

void	down(map_t *map);

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

// draw

int	draw_2d_map(sfRenderWindow *window, map_t *map, states_t *tex);
sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4);
sfVertexArray *create_line(sfVector2f point1, sfVector2f point2, sfColor color);

int	draw_background(map_t *map, surface_t *win);

int	display(surface_t *win, map_t *map, states_t *matter);

int	draw_bottom_map(sfRenderWindow *window, map_t *map, states_t *tex);

int	draw_square_selection(sfRenderWindow *window, sfVector2f **map_two_d,
								int x, int y);

int	draw_left_toolbar(surface_t *win, button_t **elem);

// loop principale

int	main_loop(int width, int height);

int	event(surface_t *win, map_t *map);

//utilitaries

sfIntRect	set_rectangle(int top, int left, int width,
								int height);

surface_t	*init_window(void);

void	save_map(map_t *map);

button_t	**create_button(void);

// event

void	analyse_event(surface_t *win, button_t **elem, map_t *map);

int	mouse_event(surface_t *win, map_t *map);

#endif
