/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
** errors
*/

#include <stdio.h>
#include "nmobjdump.h"

const int RETURN_ERR_STAT = -2;
const int RETURN_ERR_FORMAT = -3;

/*
** In the following map declaration, I would've used definied values
** if it wasn't prohibited by the norm. (H3 of Epitech's norm V2.84)
** Why can I just input a "const int" you might ask?
** Because it is not possible to use variables to initialize globals.
** That's why preprocessor directives exist.
**
** You, the one reading this, and I can both agree on the fact that
** this code is not easely maintenable.
**
** On this note, for the sake of maintenance, the codes on the lhs of the map
** correspond to the RETURN_ERR* codes. When modifying one instance above,
** do not forget to change it below as well.
**
** - The kind comment writer.
*/
const err_map_t ERRORS[] = {
	{-2, "%s: \'%s\': No such file\n"},
	{-3, "%s: %s: File format not recognized\n"},
	{0, NULL},
};

int objdump_errors(int code, const char *bin_name, const char *file_name)
{
	size_t i = 0;

	while (ERRORS[i].f_str) {
		if (ERRORS[i].code == code) {
			printf(ERRORS[i].f_str, bin_name, file_name);
			return (RETURN_ERROR);
		}
		i += 1;
	}
	return (RETURN_ERROR);
}
