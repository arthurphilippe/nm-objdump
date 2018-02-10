/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** main
*/

#include "nmobjdump.h"

const char *DEFAULT_FILE_NAME = "a.out";

int objdump_launcher(int ac, char **av)
{
	int i = 1;
	int ret = EXIT_SUCCESS;

	while (i < ac) {
		ret = objdump(av[i]);
		i += 1;
	}
	return (ret);
}

int main(int ac, char **av)
{
	int ret = EXIT_SUCCESS;

	if (ac == 1) {
		ret = objdump(DEFAULT_FILE_NAME);
	} else {
		ret = objdump_launcher(ac, av);
	}
	return ((ret == RETURN_ERROR) ? EXIT_FAILURE : EXIT_SUCCESS);
}
