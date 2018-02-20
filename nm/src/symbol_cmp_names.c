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

/*
** Computes the len of the string in a similar way nm does.
** Tho it is not certain that it is the right way.
*/
static size_t strlen_spe(const char *s)
{
	size_t len = 0;
	size_t off = 0;

	while (s[len + off]) {
		while (s[len + off] == '_')
			off += 1;
		len += 1;
	}
	return (len);
}

/*
** Compates the string in the same fashion as nm in most cases.
** Some oddities are yet to be solved.
*/
static int strcmp_spe(const char *s1, const char *s2)
{
	size_t i1 = 0;
	size_t i2 = 0;

	while (s1[i1] && s2[i2]) {
		while (s1[i1] == '_')
			i1 += 1;
		while (s2[i2] == '_')
			i2 += 1;
		if (s1[i1] == s2[i2]) {
			i1 += 1;
			i2 += 1;
		} else {
			return (s1[i1] - s2[i2]);
		}
	}
	return (strlen_spe(s1) - strlen_spe(s2));
}

/*
** Prepares the string for comparaison stripping it of its first '_'
** and by discarding the letters' case.
*/
static char *prepare_str(const char *str, int *nb_pad)
{
	char *outp;
	int i = 0;

	while (str[i] == '_')
		i += 1;
	*nb_pad = i;
	outp = strdup(&str[i]);
	if (!outp)
		return (NULL);
	i = 0;
	while (outp[i]) {
		if (islower(outp[i]))
			outp[i] = outp[i] - 'a' + 'A';
		i += 1;
	}
	return (outp);
}

/*
** Compare symbols types.
*/
static int typecmp(char t1, char t2)
{
	if (islower(t1))
		t1 = t1 - 'a' + 'A';
	if (islower(t2))
		t2 = t2 - 'a' + 'A';
	return (t1 - t2);
}

/*
** Orchestrates the entire comparaision proccess.
*/
int symbol_cmp(elf_symbol_t *s1, elf_symbol_t *s2)
{
	int nb_pad1;
	int nb_pad2;
	char *cmp1 = prepare_str(s1->name, &nb_pad1);
	char *cmp2 = prepare_str(s2->name, &nb_pad2);
	int ret;

	if (!cmp1 || !cmp2)
		return (0);
	ret = strcmp_spe(cmp1, cmp2);
	free(cmp1);
	free(cmp2);
	if (ret == 0)
		ret = strlen_spe(s1->name) - strlen_spe(s2->name);
	if (ret == 0)
		return (typecmp(s1->type, s2->type));
	return (ret);
}
