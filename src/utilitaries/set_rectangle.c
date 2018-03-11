/*
** EPITECH PROJECT, 2017
**
** File description:
**
*/

#include "header_world.h"

sfIntRect	set_rectangle(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}