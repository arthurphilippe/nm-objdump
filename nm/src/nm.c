/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "nm.h"
#include <stdio.h>

int nm(const char *file_name)
{
	void *map;
	int size;

	size = set_map_ptr(&map, file_name);
	if (size == RETURN_ERROR)
		return (RETURN_ERROR);
	printf("%d\n", size);
	return (0);
}
