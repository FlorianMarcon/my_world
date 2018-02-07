/*
** EPITECH PROJECT, 2017
** create_matrice_map
** File description:
** test
*/

#include "header_world.h"
#include <criterion/criterion.h>

Test(create_matrice_map, test1)
{
	int size = 5;
	map_t *map = create_matrice_map(size, size);

	cr_assert_neq(map, NULL);
	cr_assert_eq(map->width, size);
	cr_assert_eq(map->height, size);
	cr_assert_eq(map->map[0][0], 0);
}

Test(create_matrice_map, test2)
{
	int size = 7;
	map_t *map = create_matrice_map(size, size);

	cr_assert_neq(map, NULL);
	cr_assert_eq(map->width, size);
	cr_assert_eq(map->height, size);
	cr_assert_eq(map->map[0][0], 0);
	cr_assert_eq(map->map[size - 1][size -1], 0);
}
