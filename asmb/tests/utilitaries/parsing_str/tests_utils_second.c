/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"

Test(parsing_str, test5)
{
	char **tab = parsing_str(".name \"flonflon V2\"", ' ' | '\t');

	if (tab != NULL) {
		cr_assert_neq(tab, NULL);
		cr_assert_str_eq(tab[0], ".name");
		cr_assert_str_eq(tab[1], "\"flonflon V2\"");
		cr_assert_eq(tab[2], NULL);
	}
}
