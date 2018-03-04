/*
** EPITECH PROJECT, 2017
** my_getstr
** File description:
** my_getstr
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>

int	len_int(int nb)
{
	int a = 0;

	if (nb == 0)
		return (1);
	if (nb < 0)
		a++;
	while (nb != 0) {
		nb = nb / 10;
		a++;
	}
	return (a);
}
char	*my_getstr(int nb)
{
	char *str = malloc(sizeof(*str) * (len_int(nb) + 1));
	int i = len_int(nb);
	int var = nb;

	if (str == NULL)
		return (NULL);
	if (nb < 0) {
		var = var * -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	str[i] = '0';
	while (var != 0) {
		str[i--] = (var % 10) + '0';
		var = var / 10;
	}
	return (str);
}
