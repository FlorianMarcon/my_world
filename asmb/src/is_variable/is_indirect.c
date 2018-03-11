/*
** EPITECH PROJECT, 2017
** is_indirect
** File description:
** is_indirect
*/

#include "header_asm.h"
#include "my.h"
#include "op.h"

int	is_indirect(char *str)
{
	if (str == NULL)
		return (0);
	else if (str[0] == LABEL_CHAR)
		return (1);
	else {
		if (my_str_isnum(str))
			return (1);
		else
			return (0);
	}
}
