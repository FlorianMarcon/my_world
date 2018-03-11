/*
** EPITECH PROJECT, 2017
** my_strndup
** File description:
** my_strndup
*/

#include "my.h"
#include <stdlib.h>

char	*my_strndup(char *str, int n)
{
	int i = 0;
	char *new = NULL;

	if (str == NULL)
		return (NULL);
	if ((new = malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	while (str[i] != '\0' && i != n) {
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
