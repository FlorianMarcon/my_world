/*
** EPITECH PROJECT, 2017
** size_argument
** File description:
** size_argument
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"
int	is_registre(char *str);
int	is_indirect(char *str);
char	**parsing_str(char *str, char separator);

int	compute_size(char *arg)
{
	if (is_registre(arg))
		return (1);
	else if (is_indirect(arg))
		return (2);
	else
		return (4);

}
int	size_argument(char *str)
{
	int count = 0;
	char **tab = parsing_str(str, SEPARATOR_CHAR);

	if (tab == NULL)
		return (0);
	for (unsigned int i = 0; tab[i] != NULL; i++) {
		count += compute_size(tab[i]);
	}
	free(tab);
	return (count);
}
