/*
** EPITECH PROJECT, 2017
** create_menu
** File description:
** create_menu
*/

#include "menu.h"
#include <SFML/Graphics.h>

void	create_textbox(text_box_t *textbox, sfVector2f pos, sfFont *font)
{
	for (unsigned int i = 0; i != SIZE; i++)
		textbox->str[i] = '\0';
	textbox->text = sfText_create();
	textbox->position = pos;
	textbox->font = font;
	sfText_setFont(textbox->text, font);
	sfText_setPosition(textbox->text, pos);
}
void	create_button_menu(menu_t *menu)
{
	menu->nb_button = 2;
	set_button(&menu->button[0], (sfVector2f){1000, 400}, &menu_create_map);
	set_helptextbox(&menu->button[0], menu->font,
				"CREATE MAP : width && height = number");
	set_button_texture(&menu->button[0], "./picture/create_idle.png",
		"./picture/create_hover.png", "./picture/validated.png");
	set_button(&menu->button[1], (sfVector2f){1000, 500}, &menu_load_map);
	set_helptextbox(&menu->button[1], menu->font,
						"LOAD MAP : give path in name");
	set_button_texture(&menu->button[1], "./picture/load_idle.png",
			"./picture/load_hover.png", "./picture/validated.png");
}
void	create_menu(menu_t *menu)
{
	menu->font = sfFont_createFromFile("font/font.otf");
	create_button_menu(menu);
	menu->nb_textbox = 3;
	create_textbox(&menu->textbox[0], (sfVector2f){422, 182}, menu->font);
	create_textbox(&menu->textbox[1], (sfVector2f){330, 528}, menu->font);
	create_textbox(&menu->textbox[2], (sfVector2f){330, 628}, menu->font);
	menu->tex_back = sfTexture_createFromFile
					("./picture/background_menu.png", NULL);
	menu->spr_back = sfSprite_create();
	if (menu->spr_back != NULL)
		sfSprite_setTexture(menu->spr_back, menu->tex_back, sfFalse);
}
