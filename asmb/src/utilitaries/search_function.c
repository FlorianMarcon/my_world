/*
** EPITECH PROJECT, 2017
** search_function
** File description:
** search_function
*/

#include "header_asm.h"
#include "my.h"
#include "op.h"

int	search_function(char *str)
{
	int i = 0;

	while (op_tab[i].code != 0) {
		if (my_strcmp(str, op_tab[i].mnemonique) == 0)
			return (op_tab[i].code);
		i++;
	}
	return (0);
}
