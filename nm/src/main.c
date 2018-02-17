/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include <stdio.h>
#include "nmobjdump.h"

const char *DEFAULT_FILE_NAME = "a.out";
const int DISPLAY_NAME = 1;
const int DONT_DISPLAY_NAME = 0;

int nm_launcher(int ac, char **av)
{
	int i = 1;
	int ret;
	int final_ret = SUCCESS;

	while (i < ac) {
		if (ac != 2)
			ret = nm(av[i], DISPLAY_NAME);
		else
			ret = nm(av[i], DONT_DISPLAY_NAME);
		final_ret = (ret != SUCCESS) ? ret : final_ret;
		i += 1;
	}
	return (final_ret);
}

int main(int ac, char **av)
{
	int ret = SUCCESS;

	if (ac == 1) {
		ret = nm(DEFAULT_FILE_NAME, DONT_DISPLAY_NAME);
	} else {
		ret = nm_launcher(ac, av);
	}
	return ((ret == RETURN_ERROR) ? FAILURE : SUCCESS);
}
