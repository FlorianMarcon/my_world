/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"
#include "my.h"

Test(compute_encoding_byte, test1)
{
	char c = 248;

	cr_assert(compute_encoding_byte("r2,23,%34") == 120);
	cr_assert(compute_encoding_byte("23,45,%34") == c);
}
