/*
** EPITECH PROJECT, 2017
** is_label
** File description:
** is_label
*/

#include "header_asm.h"
#include "my.h"
#include "op.h"

int	syntax_char_is_good(char c, char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_label(char *str)
{
	int i = 0;
	int len = my_strlen(str);

	if (str == NULL)
		return (0);
	while (i != len - 1) {
		if (syntax_char_is_good(str[i], LABEL_CHARS))
			i++;
		else
			return (0);
	}
	if (str[i] == LABEL_CHAR)
		return (1);
	return (0);
}

int	is_label_variable(char *str)
{
	if (str[0] != '%' || str[1] != ':')
		return (0);
	else
		return (1);
}
