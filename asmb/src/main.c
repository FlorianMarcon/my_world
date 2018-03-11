/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <stdio.h>
#include "header_asm.h"
#include "header_world.h"
#include "my.h"
#include "op.h"

int	assembleur(char *path);

int	main(int ac, char **av)
{
	int res = 84;

	if (ac == 2)
		res = assembleur(av[1]);
	else if (ac == 1)
		main_loop();
	return (0);
}
