/*
** EPITECH PROJECT, 2017
** little_to_big_endian
** File description:
** little_to_big_endian
*/

#include "header_asm.h"
#include "my.h"

void	integer_little_to_big_endian(int *nb)
{
	char *ptr = (char *)nb;
	char pivot;

	pivot = ptr[0];
	ptr[0] = ptr[3];
	ptr[3] = pivot;
	pivot = ptr[1];
	ptr[1] = ptr[2];
	ptr[2] = pivot;
}

void	short_little_to_big_endian(short *nb)
{
	char *ptr = (char *)nb;
	char pivot;

	pivot = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = pivot;
}
