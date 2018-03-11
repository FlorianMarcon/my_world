/*
** EPITECH PROJECT, 2017
** verification_argument
** File description:
** verification_argument
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
int	verification_argument(int op_code, char *argu);
int	verification_instruction(char **tab);
int	verification_name(int fd);
int	verification_comment(int fd);
int	verification_name_and_comment(int fd);

Test(verification_argument, test1)
{
	cr_assert_eq(verification_argument(1, "%4"), 1);
	cr_assert_eq(verification_argument(1, "4"), 0);
	cr_assert_eq(verification_argument(3, "r2,r1"), 1);
	cr_assert_eq(verification_argument(3, "r2,r1,r5"), 0);
	cr_assert_eq(verification_argument(3, "r2,%2"), 0);
}

Test(verification_instruction, test1)
{
	char *tab1[3] = {"ld", "%1,r1", NULL};
	char *tab2[3] = {"ld", "%1,%1", NULL};
	char *tab3[3] = {"l", "%1,r1", NULL};
	char *tab4[3] = {"ld", NULL};

	cr_assert_eq(verification_instruction(tab1), 1);
	cr_assert_eq(verification_instruction(tab2), 0);
	cr_assert_eq(verification_instruction(tab3), 0);
	cr_assert_eq(verification_instruction(tab4), 0);
	cr_assert_eq(verification_instruction(NULL), 0);
}
Test(verification_name_and_comment, test1)
{
	int fd = open("data/data1.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name(fd), 1);
		cr_assert_eq(verification_comment(fd), 1);
		close(fd);
	}
}

Test(verification_name_and_comment, test2)
{
	int fd = open("data/data2.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name(fd), 0);
		cr_assert_eq(verification_comment(fd), 0);
		close(fd);
	}
}

Test(verification_name_and_comment, test3)
{
	int fd = open("data/data_empty.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name(fd), 0);
		cr_assert_eq(verification_comment(fd), 0);
		close(fd);
	}
}
