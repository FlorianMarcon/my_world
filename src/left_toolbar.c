/*
** EPITECH PROJECT, 2017
** create_matrice_map
** File description:
** create_matrice_map
*/

#include "my.h"
#include "header_world.h"

typedef struct scene_s {
	struct game_object_s *objs;
	struct button_s *buttons[3];
} scene_t;

typedef struct button_s {
	sfRectangleShape *rect;
	void (*callback)(int *);
} button_t;

typedef struct game_object_s {
	sfSprite *sprite_obj;
	sfTexture *texture_obj;
	sfVector2f pos;
	sfIntRect rect_obj;
} game_object_t;

void kitchen(int *boolean)
{
	*boolean = 1;
}

void restaurant(int *boolean)
{
	*boolean = 0;
}

void outsidem(int *boolean)
{
	*boolean = 2;
}

void exitgame(int *boolean)
{
	*boolean = 3;
}

int buttonIsClicked(button_t button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button.rect).x +
	sfRectangleShape_getSize(button.rect).x &&
	clickPosition.x > sfRectangleShape_getPosition(button.rect).x &&
	clickPosition.y < sfRectangleShape_getPosition(button.rect).y +
	sfRectangleShape_getSize(button.rect).y &&
	clickPosition.y > sfRectangleShape_getPosition(button.rect).y);
}

game_object_t *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
	game_object_t	*elem = malloc(sizeof(*elem) * 1);

	elem->texture_obj = sfTexture_createFromFile(path_to_spritesheet, NULL);
	elem->sprite_obj = sfSprite_create();
	elem->rect_obj.top = rect.top;
	elem->rect_obj.left = rect.left;
	elem->rect_obj.width = rect.width;
	elem->rect_obj.height = rect.height;
	elem->pos.x = pos.x;
	elem->pos.y = pos.y;
	sfSprite_setPosition(elem->sprite_obj, pos);
	return(elem);
}

void my_drawSprite(sfRenderWindow *window, game_object_t *elem)
{
	sfSprite_setPosition(elem->sprite_obj, elem->pos);
	sfSprite_setTexture(elem->sprite_obj, elem->texture_obj, sfTrue);
	sfSprite_setTextureRect(elem->sprite_obj, elem->rect_obj);
	sfRenderWindow_drawSprite(window, elem->sprite_obj, NULL);
}

void drawscene(sfRenderWindow *window, scene_t **scene, int num_buttons, int num_sprite, int boolean)
{
	sfRenderWindow_clear(window, sfBlack);
	if (boolean < 3) {
	for (int i = 0; i < num_sprite; i++)
		my_drawSprite(window, scene[boolean]->objs);
	for (int j = 0; j < num_buttons; j++)
		sfRenderWindow_drawRectangleShape(window, scene[boolean]->buttons[j]->rect, NULL);
	}
}

void analyse_event(sfRenderWindow *window, sfEvent event, button_t *restaurant, button_t *kitchen, button_t *outside, int num_rep, int *boolean)
{
	sfVector2i clickPosition_one;
	sfVector2f clickPosition;

	while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed || *boolean == 3)
				sfRenderWindow_close(window);
			if (event.type == sfEvtMouseButtonPressed) {
				clickPosition_one = sfMouse_getPosition((const sfWindow *)window);
				clickPosition.x = clickPosition_one.x;
				clickPosition.y = clickPosition_one.y;
				for (int i = 0; i < num_rep; i++) {
					if (*boolean == 0) {
						if (buttonIsClicked(restaurant[i], clickPosition))
							restaurant[i].callback(boolean);
					} else if (*boolean == 1) {
						if (buttonIsClicked(kitchen[i], clickPosition))
							kitchen[i].callback(boolean);
					} else if (*boolean == 2) {
						if (buttonIsClicked(outside[i], clickPosition))
							outside[i].callback(boolean);
					}
				}
			}
		}
}

button_t *buttonInitialise(button_t *button, sfVector2f position, sfVector2f size, void (*callback)(int *boolean), sfColor color, game_object_t *rooms)
{
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setTexture(button->rect, rooms->texture_obj, sfTrue);
	sfRectangleShape_setTextureRect(button->rect, rooms->rect_obj);
	sfRectangleShape_setSize(button->rect, size);
	//sfRectangleShape_setFillColor(button->rect, color);
	button->callback = callback;
	return (button);
}

sfIntRect set_rectangle(sfIntRect rect, int top, int left, int width, int height)
{
	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

void destroy_object(game_object_t *elem)
{
	sfTexture_destroy(elem->texture_obj);
	sfSprite_destroy(elem->sprite_obj);
	free(elem);
}


scene_t *create_scene(scene_t *scene, game_object_t *objs, button_t **buttons)
{
	scene->objs = objs;
	scene->buttons[0] = buttons[0];
	scene->buttons[1] = buttons[1];
	scene->buttons[2] = buttons[2];
	return (scene);
}

int test(void)
{

	button_t button_scene1_scne2;
	button_t button_exitgame;
	button_t button_pause_game;
	button_t *elem[3];

	scene_t scene;
	scene_t scene_kit;
	scene_t outside;
	scene_t *scenes[3];
	int num_buttons = 3;
	int num_sprite = 1;
	int boolean = 0;

	button_t chicken;
	button_t salad;
	button_t cake;
	button_t *kit_elem[3];

	button_t bins;
	button_t kit;
	button_t inside;
	button_t *out_elem[3];

	//////////////////////
	sfSprite *sprite_plus;
	sfTexture *texture_plus;
	sfIntRect rect_plus;
	texture_plus = sfTexture_createFromFile("smaller.png", NULL);
	sprite_plus = sfSprite_create();
	rect_plus.top = 0;
	rect_plus.left = 0;
	rect_plus.width = 100;
	rect_plus.height = 100;
	sfSprite_setTexture(sprite_plus, texture_plus, sfTrue);
	sfSprite_setTextureRect(sprite_plus, rect_plus);
	//////////////////////

	game_object_t *rooms[6];
	sfIntRect rect_restaurant;
	sfIntRect rect_kitchen;
	sfIntRect rect_outside;
	sfIntRect rect_larger;
	sfIntRect rect_smaller;
	sfIntRect rect_return;

	rect_restaurant = set_rectangle(rect_restaurant, 0,0,800,600);
	rooms[0] = create_object("resto.png", (sfVector2f){0, 0}, rect_restaurant);
	rect_kitchen = set_rectangle(rect_kitchen, 0,0,800,600);
	rooms[1] = create_object("kitchen.jpg", (sfVector2f){0, 0}, rect_kitchen);
	rect_outside = set_rectangle(rect_outside, 0,0,1500,1600);
	rooms[2] = create_object("outside.jpg", (sfVector2f){-250, -300}, rect_outside);
	rect_larger = set_rectangle(rect_larger, 0,0,100,100);
	rooms[3] = create_object("larger.png", (sfVector2f){-250, -300}, rect_larger);
	rect_smaller = set_rectangle(rect_smaller, 0,0,100,100);
	rooms[4] = create_object("smaller.png", (sfVector2f){-250, -300}, rect_smaller);
	rect_return = set_rectangle(rect_return, 0,0,100,100);
	rooms[5] = create_object("return.png", (sfVector2f){-250, -300}, rect_return);

	elem[0] = buttonInitialise(&button_scene1_scne2, (sfVector2f){30, 10}, (sfVector2f){100, 100}, kitchen, sfYellow, rooms[3]);
	elem[1] = buttonInitialise(&button_exitgame, (sfVector2f){30, 250}, (sfVector2f){100, 100}, exitgame, sfBlack, rooms[5]);
	elem[2] = buttonInitialise(&button_pause_game, (sfVector2f){30, 450}, (sfVector2f){100, 100}, outsidem, sfBlue, rooms[3]);

	kit_elem[0] = buttonInitialise(&chicken, (sfVector2f){30, 10}, (sfVector2f){100, 100}, restaurant, sfRed, rooms[4]);
	kit_elem[1] = buttonInitialise(&salad, (sfVector2f){30, 250}, (sfVector2f){100, 100}, exitgame, sfBlack, rooms[5]);
	kit_elem[2] = buttonInitialise(&cake, (sfVector2f){30, 450}, (sfVector2f){100, 100}, outsidem, sfBlue, rooms[3]);

	out_elem[0] = buttonInitialise(&bins, (sfVector2f){30, 10}, (sfVector2f){100, 100}, restaurant, sfRed, rooms[4]);
	out_elem[1] = buttonInitialise(&kit, (sfVector2f){30, 250}, (sfVector2f){100, 100}, exitgame, sfBlack, rooms[5]);
	out_elem[2] = buttonInitialise(&inside, (sfVector2f){30, 450}, (sfVector2f){100, 100}, kitchen, sfYellow, rooms[3]);

	scenes[0] = create_scene(&scene, rooms[0], elem);
	scenes[1] = create_scene(&scene_kit, rooms[1], kit_elem);
	scenes[2] = create_scene(&outside, rooms[2], out_elem);

	while (sfRenderWindow_isOpen(window)) {
		analyse_event(window, event, *elem, *kit_elem, *out_elem, 3, &boolean);
		drawscene(window, scenes, num_buttons, num_sprite, boolean);
		sfRenderWindow_display(window);
	}
	/*for (int i = 0; i < 3; i++) {
		sfRectangleShape_destroy(elem[i]->rect);
		sfRectangleShape_destroy(kit_elem[i]->rect);
	}
	destroy_object(*rooms);
	sfRenderWindow_destroy(window);*/
	return (0);
}