/*
** EPITECH PROJECT, 2017
** main_loop
** File description:
** main_loop
*/

#include "header_world.h"

file_t		*create_text(void)
{
	file_t		*textfile = malloc(sizeof(*textfile) * 1);
	textfile->font = sfFont_createFromFile("./src/arial.ttf");
	textfile->text = sfText_create();
	sfText_setFont(textfile->text ,textfile->font);
	sfText_setFillColor(textfile->text, sfRed);
	sfText_setCharacterSize(textfile->text, 35);
	textfile->counter = 0;
	textfile->str = NULL;
	textfile->str = my_calloc(textfile->str, sizeof(char) * 20);
	textfile->pos = (sfVector2f){720, 662};
	return (textfile);
}
