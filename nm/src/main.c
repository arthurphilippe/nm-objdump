/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include <stdio.h>
#include "nmobjdump.h"
#include "nm_errors.h"

int nm_launcher(int ac, char **av)
{
	int i = 1;
	int ret;
	int final_ret = SUCCESS;

	while (i < ac) {
		if (ac != 2)
			ret = nm(av[i], DISPLAY_NAME, av[0]);
		else
			ret = nm(av[i], DONT_DISPLAY_NAME, av[0]);
		final_ret = (ret != SUCCESS) ? ret : final_ret;
		i += 1;
	}
	return (final_ret);
}

int main(int ac, char **av)
{
	int ret;

	if (ac == 1) {
		ret = nm(DEFAULT_FILE_NAME, DONT_DISPLAY_NAME, av[0]);
	} else {
		ret = nm_launcher(ac, av);
	}
	return ((ret == RETURN_ERROR) ? FAILURE : SUCCESS);
}
