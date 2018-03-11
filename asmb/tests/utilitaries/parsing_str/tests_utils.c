/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"
int	nb_element(char *str, char sep);
char	**parsing_str(char *str, char separator);

Test(nb_element, test1)
{
	cr_assert_eq(nb_element(",,yes,oui", ','), 2);
	cr_assert_eq(nb_element("r1,r2,r3", ','), 3);
}


Test(parsing_str, test1)
{
	char **tab = parsing_str("r1,r2,r3", ',');

	cr_assert_neq(tab[0], NULL);
	cr_assert_str_eq(tab[0], "r1");
	cr_assert_str_eq(tab[1], "r2");
	cr_assert_str_eq(tab[2], "r3");
	cr_assert_eq(tab[3], NULL);
}
Test(parsing_str, tes2)
{
	char **tab = parsing_str(".name \"flonflon\"", ' ');

	cr_assert_neq(tab[0], NULL);
	cr_assert_str_eq(tab[0], ".name");
	cr_assert_str_eq(tab[1], "\"flonflon\"");
	cr_assert_eq(tab[2], NULL);

}

Test(parsing_str, test3)
{
	int fd = open("data/data1.s", O_RDONLY);
	char *str;

	if ((str = get_next_line(fd)) != NULL) {
		char **tab = parsing_str(str, ' ');
		cr_assert_neq(tab[0], NULL);
		cr_assert_str_eq(tab[0], ".name");
		cr_assert_str_eq(tab[1], "\"flonflon\"");
		cr_assert_eq(tab[2], NULL);
	}
}
Test(parsing_str, test4)
{
	char **tab = parsing_str("a	b c", ' ' | '\t');

	if (tab != NULL) {
		cr_assert_neq(tab, NULL);
		cr_assert_str_eq(tab[0], "a");
		cr_assert_str_eq(tab[1], "b");
		cr_assert_str_eq(tab[2], "c");
		cr_assert_eq(tab[3], NULL);
	}
}
