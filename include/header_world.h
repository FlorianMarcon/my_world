/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef COREWAR_
#define COREWAR_


#define BACKGROUND "picture/background.jpg"

typedef struct surface_s {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
	sfSprite //;
}surface_t;

typedef	struct scene_s {
	struct game_object_s *objs;
	struct button_s *buttons[3];
} scene_t;

typedef struct init {
	char *path;
	void (*callback)( *);
}init_t;

typedef	struct button_s {
	sfRectangleShape *rect;
	void (*callback)( *);
} button_t;

typedef	struct game_object_s {
	sfSprite *sprite_obj;
	sfTexture *texture_obj;
	sfVector2f pos;
	sfIntRect rect_obj;
} game_object_t;

int	draw_background(surface_t *win);

int	display(surface_t *win);

int	main_loop(int width, int height);

int	event(surface_t *win);

sfIntRect	set_rectangle(int top, int left, int width,
						int height);

surface_t	*init_window(void);

button_t	**create_button(void);

void	analyse_event(surface_t *win);

int	mouse_event(surface_t *win);

#endif
