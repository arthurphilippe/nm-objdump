/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** main
*/

#include "nmobjdump.h"

const char *DEFAULT_FILE_NAME = "a.out";
const int DISPLAY_NAME = 1;
const int DONT_DISPLAY_NAME = 0;

int objdump_launcher(int ac, char **av)
{
	int i = 1;
	int ret = SUCCESS;

	while (i < ac) {
		ret = objdump(av[i], av[0]);
		i += 1;
	}
	return (ret);
}

int main(int ac, char **av)
{
	int ret = SUCCESS;

	if (ac == 1) {
		ret = objdump(DEFAULT_FILE_NAME, av[0]);
	} else {
		ret = objdump_launcher(ac, av);
	}
	return ((ret == RETURN_ERROR) ? FAILURE : SUCCESS);
}
