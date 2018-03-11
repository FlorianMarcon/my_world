/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "op.h"
int	is_registre(char *str);
int	syntax_char_is_good(char c, char *str);
int	is_label(char *str);
int	is_direct(char *str);

Test(is_registre, test1)
{
	cr_assert_eq(is_registre("r1"), 1);
	cr_assert_eq(is_registre("r16"), 16);
	cr_assert_eq(is_registre("r9"), 9);
	cr_assert_eq(is_registre("rally"), 0);
	cr_assert_eq(is_registre("r"), 0);
	cr_assert_eq(is_registre("a1"), 0);
	cr_assert_eq(is_registre("r-2"), 0);
	cr_assert_eq(is_registre("r99"), 0);
}

Test(syntax_char_is_good, test1)
{
	cr_assert_eq(syntax_char_is_good('a', LABEL_CHARS), 1);
	cr_assert_eq(syntax_char_is_good(':', LABEL_CHARS), 0);
}

Test(is_label, test1)
{
	cr_assert_eq(is_label("live:"), 1);
	cr_assert_eq(is_label("Live:"), 0);
	cr_assert_eq(is_label("live"), 0);
}
Test(is_direct, test1)
{
	cr_assert_eq(is_direct("%1234"), 1);
	cr_assert_eq(is_direct("%-1234"), 1);
	cr_assert_eq(is_direct("46N"), 0);
	cr_assert_eq(is_direct("%:live"), 1);
	cr_assert_eq(is_direct("%live"), 0);
}
