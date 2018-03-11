/*
** EPITECH PROJECT, 2017
** size_function
** File description:
** size_function
*/

#include "header_asm.h"
#include "my.h"
int	search_function(char *str);

int	size_function(char *str)
{
	int op_c = search_function(str);
	int res = 1;

	switch (op_c) {
		case 1: break;
		case 9: break;
		case 12: break;
		case 15: break;
		default : res = 2;
			break;
	}
	return (res);
}
