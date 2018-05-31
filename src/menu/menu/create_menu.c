/*
** EPITECH PROJECT, 2017
** create_menu
** File description:
** create_menu
*/

#include "menu.h"

void	create_button_menu(menu_t *menu)
{
	menu->nb_button = 1;
	set_button(&menu->button[0], (sfVector2f){0, 0}, NULL);
	set_helptextbox(&menu->button[0], menu->font, "PLUS");
	set_button_texture(&menu->button[0], "./picture/smaller_idle.png", "./picture/smaller_hover.png", "./picture/smaller_clicked.png");
}
void	create_menu(menu_t *menu)
{
	menu->font = sfFont_createFromFile("font/font.otf");
	create_button_menu(menu);
}
