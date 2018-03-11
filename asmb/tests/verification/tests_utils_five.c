/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"

Test(verification_file, test1)
{
	analyse_file_t *an = NULL;

	an = verification_file("bad_path");
	cr_assert_eq(an, NULL);
	an = verification_file("../data/bad_champion_label.s");
	cr_assert_eq(an, NULL);
}

Test(verification_file, test2)
{
	analyse_file_t *an = NULL;

	an = verification_file("data/flonflon.v.2.s");
	cr_assert_neq(an, NULL);
	free(an);
}
