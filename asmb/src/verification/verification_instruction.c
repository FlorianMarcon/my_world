/*
** EPITECH PROJECT, 2017
** verification_instruction
** File description:
** verification_instruction
*/

#include <stdlib.h>
#include "header_asm.h"
#include "op.h"
int	len_tab(char **tab);
int	verification_argument(int op_code, char *argu);
int	search_function(char *str);

int	verification_instruction(char **tab)
{
	int op_c;
	int count;

	if (tab == NULL)
		return (0);
	if (len_tab(tab) != 2 || (op_c = search_function(tab[0])) == 0)
		return (0);
	else if ((count = verification_argument(op_c, tab[1])) == 0)
		return (0);
	else
		return (count);
}
