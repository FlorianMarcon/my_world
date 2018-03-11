/*
** EPITECH PROJECT, 2017
** size_instruction
** File description:
** size_instruction
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"
int	size_function(char *str);
int	size_argument(char *str);

int	size_ldi(char *argu)
{
	char **tab = parsing_str(argu, SEPARATOR_CHAR);
	int count = 2;

	if (which_variable(tab[0]) == T_REG)
		count += 1;
	else
		count += 2;
	if (which_variable(tab[1]) == T_REG)
		count += 1;
	else
		count += 2;
	count += 1;
	free(tab);
	return (count);
}

int	size_sti(char *argu)
{
	char **tab = parsing_str(argu, SEPARATOR_CHAR);
	int count = 2;

	count += 1;
	if (which_variable(tab[1]) == T_REG)
		count += 1;
	else
		count += 2;
	if (which_variable(tab[2]) == T_REG)
		count += 1;
	else
		count += 2;
	free(tab);
	return (count);
}
int	size_instruction(char **tab)
{
	int count = 0;
	int var = search_function(tab[0]);

	switch(var) {
		case 9: count = 3;
			break;
		case 10: count = size_ldi(tab[1]);
			break;
		case 11: count = size_sti(tab[1]);
			break;
		case 12: count += 3;
			break;
		default:count += size_function(tab[0]);
			count += size_argument(tab[1]);
			break;
	}
	return (count);
}
