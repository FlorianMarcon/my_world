/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** know if str is num
*/

#include <unistd.h>
#include <stdio.h>

int	my_str_isnum(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
