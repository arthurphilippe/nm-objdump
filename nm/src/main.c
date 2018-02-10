/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include "nmobjdump.h"

const char *DEFAULT_FILE_NAME = "a.out";

int nm_launcher(int ac, char **av)
{
	int i = 1;
	int ret = EXIT_SUCCESS;

	while (i < ac) {
		ret = nm(av[i]);
		i += 1;
	}
	return (ret);
}

int main(int ac, char **av)
{
	int ret = EXIT_SUCCESS;

	if (ac == 1) {
		ret = nm(DEFAULT_FILE_NAME);
	} else {
		ret = nm_launcher(ac, av);
	}
	return ((ret == RETURN_ERROR) ? EXIT_FAILURE : EXIT_SUCCESS);
}
