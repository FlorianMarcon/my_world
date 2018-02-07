/*
** EPITECH PROJECT, 2017
** test_utils
** File description:
** create_list_texture
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "header_world.h"

Test(create_list_texture, test1)
{
	states_t *text = create_list_texture();
	int i = 0;
	int nb_matter = 3;

	cr_assert_neq(text, NULL);
	while (text[i].matter != null)
		i++;
	cr_assert_eq(i, nb_matter);
}
