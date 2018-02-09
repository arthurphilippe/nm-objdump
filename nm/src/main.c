/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include "nm.h"

int nm_launcher(int ac, char **av)
{
	int i = 1;
	int ret = EXIT_SUCCESS;

	while (i < ac) {

		i += 1;
	}
}

int main(int ac, char **av)
{
	int ret = EXIT_SUCCESS;

	if (ac == 1) {
		// launch with a.out
	} else {
		ret = nm_launcher(ac, av);
	}
}
