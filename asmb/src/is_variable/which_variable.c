/*
** EPITECH PROJECT, 2017
** which_variable
** File description:
** which_variable
*/

#include "header_asm.h"
#include "op.h"
int	is_indirect(char *str);
int	is_direct(char *str);
int	is_registre(char *str);

int	which_variable(char *str)
{
	if (is_indirect(str))
		return (T_IND);
	else if (is_direct(str))
		return (T_DIR);
	else if (is_registre(str))
		return (T_REG);
	else
		return (0);
}
