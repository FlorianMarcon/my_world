/*
** EPITECH PROJECT, 2017
** instruction_is_valid
** File description:
** instruction_is_valid
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"

void	delete_commentary(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != COMMENT_CHAR)
		i++;
	if (i > 0 && str[i] == COMMENT_CHAR) {
		i--;
		while ((str[i] == ' ' || str[i] == '\t') && i >= 0)
			i--;
		str[++i] = '\0';
	} else
		str[i] = '\0';
}
void	delete_inutile_space(char **str)
{
	int i = 0;
	char *msg = *str;

	while (msg[i] == ' ' || msg[i] == '\t')
		i++;
	*str = &msg[i];
}
int	syntax_instruction_is_valid(char **msg)
{
	char *str = NULL;;

	if (msg == NULL || *msg == NULL)
		return (-1);
	str = *msg;
	delete_commentary(str);
	delete_inutile_space(&str);
	if (my_strlen(str) == 0)
		return (0);
	*msg = str;
	return (1);
}
