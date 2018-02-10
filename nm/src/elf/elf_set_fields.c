/*
** EPITECH PROJECT, 2018
** nm
** File description:
** set elf fields
*/

#include <stdio.h>
#include <unistd.h>
#include "nm.h"

int set_elf_fields(elf_t *elf, void *maped_file)
{
	elf->addr = maped_file;
	elf->ehdr = maped_file;
	if (!elf_validate_format(elf)) {
		dprintf(STDERR_FILENO, "File format not recognized\n");
		return (RETURN_ERROR);
	}
	return (0);
}
