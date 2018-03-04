/*
** EPITECH PROJECT, 2017
** save_map
** File description:
** save_map
*/

#include "header_world.h"
#include <stdio.h>
#include "my.h"
char	*my_getstr(int nb);

void	save_map(map_t *map)
{
	FILE *file = fopen(MEMORY, "w");
	char *str = my_strcat(my_getstr(map->height), " ");

	if (file == NULL)
		return;
	fwrite(str, 1, my_strlen(str), file);
	str = my_strcat(my_getstr(map->width), " ");
	fwrite(str, 1, my_strlen(str), file);
	fclose(file);
}
