/*
** EPITECH PROJECT, 2017
** get_next_instruction
** File description:
** get_next_instruction
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "get_next_line.h"
int	syntax_instruction_is_valid(char **msg);
char	*recuperate_string(char *str);

char	*get_next_instruction(int fd)
{
	char *str = NULL;

	while (str == NULL) {
		str = get_next_line(fd);
		switch (syntax_instruction_is_valid(&str)) {
			case 0: free (str);
				str = NULL;
				break;
			case -1: return (NULL);
				break;
			default: break;
		}
	}
	return (str);
}

char	*get_next_instruction_simply(int fd)
{
	char *str = NULL;

	while (str == NULL) {
		str = get_next_line(fd);
		delete_commentary(str);
		delete_inutile_space(&str);
		if (my_strlen(str) == 0) {
			free(str);
			str = NULL;
		}
	}
	return (str);
}
