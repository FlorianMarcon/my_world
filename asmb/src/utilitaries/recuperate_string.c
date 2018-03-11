/*
** EPITECH PROJECT, 2017
** recuperate_string
** File description:
** recuperate_string
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"

char	*recuperate_string(char *str)
{
	char *new = malloc(sizeof(char) * my_strlen(str));
	int i = 0;
	int a = 0;

	if (new == NULL)
		return (NULL);
	while (str[i] != '"' && str[i] != '\0')
		i++;
	if (str[i++] == '\0') {
		free(new);
		return (NULL);
	}
	while (str[i] != '"' && str[i] != '\0')
		new[a++] = str[i++];
	if (str[i] == '\0') {
		free(new);
		return (NULL);
	}
	new[a] = '\0';
	return (new);
}
