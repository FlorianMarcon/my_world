/*
** EPITECH PROJECT, 2017
** calculate_encoding_byte
** File description:
** calculate_encoding_byte
*/

#include "header_asm.h"
#include "my.h"
#include "op.h"

char	compute_encoding_byte(char *argu)
{
	char **tab = parsing_str(argu, SEPARATOR_CHAR);
	int i = 0;
	char res = 0;
	int var;

	while (tab[i] != NULL) {
		var = which_variable(tab[i++]);
		res = res << 2;
		switch (var) {
			case T_IND: res += 3;
			break;
			case T_DIR: res += 2;
			break;
			case T_REG: res += 1;
			break;
		}
	}
	while (i++ != 4)
		res = res << 2;
	return (res);
}
