/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
char	*my_strndup(char *str, int n);

Test(my_strndup, test1)
{
	char *str = my_strndup("salut", 2);

	cr_assert_str_eq(str, "sa");
	free(str);
	str = my_strndup("aa", 5);
	cr_assert_str_eq(str, "aa");
	free(str);
	str = NULL;
	cr_assert_eq(str, NULL);
}
