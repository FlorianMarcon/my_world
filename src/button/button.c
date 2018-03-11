/*
** EPITECH PROJECT, 2017
** left_diztoolbar
** File description:
** de
*/

#include <stdio.h>
#include "header_world.h"

int	assembleur(char *path);

void compile(char *str)
{
	int i = 0;

	printf("%s\n", str);
	i = assembleur(str);
	printf("%d\n", i);
}

void name1(char *str)
{
	printf("name\n");
}