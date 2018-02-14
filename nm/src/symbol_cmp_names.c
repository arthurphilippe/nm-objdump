/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** names
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "nmobjdump.h"

static char *prepare_str(const char *str)
{
	char *outp;
	int i = 0;

	while (str[i] == '_') {
		i += 1;
	}
	outp = strdup(&str[i]);
	if (!outp)
		return (NULL);
	i = 0;
	// while (outp[i]) {
	// 	if (islower(outp[i]))
	// 		outp[i] = outp[i] - 'a' + 'A';
	// 	i += 1;
	// }
	return (outp);
}

int symbol_cmp_names(const char *s1, const char *s2)
{
	char *cmp1 = prepare_str(s1);
	char *cmp2 = prepare_str(s2);
	int ret;

	if (!cmp1 || !cmp2)
		return (0);
	ret = strcmp(cmp1, cmp2);
	free(cmp1);
	free(cmp2);
	return (ret);
}
