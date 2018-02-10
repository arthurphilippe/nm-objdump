/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include <stdio.h>
#include "nm.h"

const int EXIT_FAILURE = 1;
const int EXIT_SUCCESS = 0;
const int RETURN_ERROR = -1;
const int RETURN_OK = 0;

int nm(const char *file_name)
{
	void *map;
	int size;
	elf_t elf;

	size = set_map_ptr(&map, file_name);
	if (size == RETURN_ERROR)
		return (RETURN_ERROR);
	if (elf_set_fields(&elf, map) != 0)
		return (RETURN_ERROR);
	return (0);
}
