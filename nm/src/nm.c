/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include <stdio.h>
#include "nm.h"

int nm(const char *file_name)
{
	void *map;
	int size;
	elf_t elf;

	size = set_map_ptr(&map, file_name);
	if (size == RETURN_ERROR)
		return (RETURN_ERROR);
	if (set_elf_fields(&elf, map) != 0)
		return (RETURN_ERROR);
	return (0);
}
