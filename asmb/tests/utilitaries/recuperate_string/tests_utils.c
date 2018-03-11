/*
** EPITECH PROJECT, 2017
** recuperate_string
** File description:
** recuperate_string
*/

#include "header_asm.h"
#include <criterion/criterion.h>
char	*recuperate_string(char *str);

Test(recuperate_string, test1)
{
	char *s = recuperate_string(".name	\"salut toi\"");

	cr_assert_str_eq(s, "salut toi");
}
