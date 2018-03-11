/*
** EPITECH PROJECT, 2017
** verification_argument
** File description:
** verification_argument
*/

#include <stdbool.h>
#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"
char	**parsing_str(char *str, char separator);
int	which_variable(char *str);
int	len_tab(char **tab);

int	verification_argument(int op_code, char *argu)
{
	char **tab;
	int var;

	if (argu == NULL)
		return (-1);
	tab = parsing_str(argu, SEPARATOR_CHAR);
	if (len_tab(tab) != op_tab[op_code - 1].nbr_args) {
		free (tab);
		return (0);
	}
	for (unsigned int i = len_tab(tab); i--;) {
		var = which_variable(tab[i]);
		if ((var & op_tab[op_code - 1].type[i]) == 0) {
			free(tab);
			return (0);
		}
	}
	free(tab);
	return (1);
}
