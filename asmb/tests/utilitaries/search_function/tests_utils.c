/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"
int	search_function(char *str);

Test(search_function, test1)
{
	cr_assert_eq(search_function("live"), 1);
	cr_assert_eq(search_function("aff"), 16);
	cr_assert_eq(search_function("cezfhjca,q"), 0);
}
