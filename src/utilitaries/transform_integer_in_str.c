/*
** EPITECH PROJECT, 2017
** transform_integer_in_str
** File description:
** transform_integer_in_str
*/

#include <stdlib.h>
#include "my.h"

char	*transform_integer_in_str(int nb)
{
	int size = lenint(nb);
	char *str = malloc(sizeof(*str) * (size + 2));
	int tmp = 0;

	if (str == NULL)
		return (NULL);
	if (nb == 0) {
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	for (int i = size - 1; i >= 0; i--) {
		tmp = nb % 10;
		str[i] = '0' + tmp;
		nb = (nb - tmp) / 10;
	}
	str[size] = '\0';
	return (str);
}
