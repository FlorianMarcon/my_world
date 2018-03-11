/*
** EPITECH PROJECT, 2017
** is_direct
** File description:
** is_direct
*/

#include "header_asm.h"
#include "my.h"
#include "op.h"

int	is_direct(char *str)
{
	if (str == NULL || str[0] != DIRECT_CHAR)
		return (0);
	if (str[1] == LABEL_CHAR) {
		return (1);
	} else if (my_str_isnum(&str[1]))
		return (1);
	else
		return (0);
}
