/*
** EPITECH PROJECT, 2017
** parsing_str
** File description:
** parsing_str
*/

#include "my.h"
#include <stdlib.h>

int	nb_separtor(char *str, char lab)
{
	int size = 1;

	for (unsigned int i = 0; str[i] != '\0'; i++) {
		if (str[i] == lab)
			size++;
	}
	return (size);
}
void	parsing_str_stock(char **tab, char *str, char lab)
{
	unsigned int where = 0;

	if (str[0] != lab) {
		tab[where++] = &str[0];
	}
	for (unsigned int i = 1; str[i] != '\0'; i++) {
		if (str[i] == lab)
			str[i] = '\0';
		if (str[i - 1] == '\0' && str[i] != '\0')
			tab[where++] = &str[i];
	}
	tab[where] = NULL;
}
char	**parsing_str(char *str, char lab)
{
	int size = nb_separtor(str, lab);
	char **tab = malloc(sizeof(*tab) * size + 1);

	if (str == NULL)
		return (NULL);
	size = nb_separtor(str, lab);
	if ((tab = malloc(sizeof(*tab) * (size + 1))) == NULL)
		return (NULL);
	parsing_str_stock(tab, str, lab);
	for (unsigned int i = 0; tab[i] != NULL; i++)
		tab[i] = my_strdup(tab[i]);
	return (tab);
}
