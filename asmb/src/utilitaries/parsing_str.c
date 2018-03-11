/*
** EPITECH PROJECT, 2017
** parsing_str
** File description:
** parsing_str
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"

int	nb_element(char *str, char sep)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if ((str[i] & sep) == str[i] && i != 0 && (str[i - 1] & sep) != str[i - 1])
			nb++;
		i++;
	}
	nb++;
	return (nb);
}

int	len_until_separator(char *str, char sep)
{
	int i = 0;
	int cote = 1;

	while (str[i] != '\0') {
		if ((str[i] & sep) == str[i] && cote == 1)
			return (i);
		if (str[i] == '"')
			cote = cote * -1;
		i++;
	}
	return (i);
}

char	**parsing_str(char *str, char separator)
{
	char **tab = NULL;
	int i = 0;
	int a = 0;
	int c = 0;

	if (str == NULL)
		return (NULL);
	tab = malloc(sizeof(*tab) * (nb_element(str, separator) + 1));
	if (tab == NULL)
		return (NULL);
	while (i < my_strlen(str) && str[i] != '\0') {
		if ((str[i] & separator) == str[i]) {
			i++;
		} else {
			c = len_until_separator(&str[i], separator);
			tab[a] = malloc(sizeof(*tab[a]) * (c + 1));
			my_strncpy(tab[a++], &str[i], c);
			i += c;
		}
	}
	tab[a] = NULL;
	return (tab);
}
