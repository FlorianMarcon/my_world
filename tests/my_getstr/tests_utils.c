/*
** EPITECH PROJECT, 2017
** my_getstr
** File description:
** my_getstr
*/

#include <criterion/criterion.h>
#include <stdio.h>
char	*my_getstr(int nb);
int	len_int(int nb);

Test(len_int, test1)
{
	cr_assert_eq(len_int(13), 2);
	cr_assert_eq(len_int(0), 1);
	cr_assert_eq(len_int(-13), 3);
}

Test(my_getstr, test1)
{
	cr_assert_str_eq(my_getstr(13), "13");
	cr_assert_str_eq(my_getstr(-13), "-13");
//	cr_assert_str_eq(my_getstr(0), "0");
}
