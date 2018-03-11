/*
** EPITECH PROJECT, 2017
** len_tab
** File description:
** len_tab
*/

#include <criterion/criterion.h>
int	len_tab(char **tab);

Test(len_tab, test1)
{
	char *tab[3] = {"yes", "no", NULL};

	cr_assert_eq(len_tab(NULL), -1);
	cr_assert_eq(len_tab(tab), 2);
}
