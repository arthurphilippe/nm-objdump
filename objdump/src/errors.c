/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
** errors
*/

#include <stdio.h>
#include "nmobjdump.h"
#include "nm_errors.h"

int nm_errors(int code, const char *bin_name, const char *file_name)
{
	static const err_map_t errors[] = {
		{RETURN_ERR_STAT, "%s: \'%s\': No such file\n"},
		{RETURN_ERR_FORMAT, "%s: %s: File format not recognized\n"},
		{0, NULL},
	};
	size_t i = 0;

	while (errors[i].f_str) {
		if (errors[i].code == code) {
			printf(errors[i].f_str, bin_name, file_name);
			return (RETURN_ERROR);
		}
		i += 1;
	}
	return (RETURN_ERROR);
}
