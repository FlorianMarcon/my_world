/*
** EPITECH PROJECT, 2017
** is_registre
** File description:
** is_registre
*/

#include "my.h"
#include "op.h"

// return nb registre if true or 0 if false

int	is_registre(char *str)
{
	int nb;

	if (my_strlen(str) < 2 || my_strlen(str) > 3)
		return (0);
	nb = my_getnbr(&str[1]);
	if (str[0] != 'r' || nb < 1  || nb > REG_NUMBER)
		return (0);
	else
		return (nb);
}
