/*
** EPITECH PROJECT, 2018
** nm
** File description:
** set elf fields
*/

#include "nm.h"

int set_elf_fields(elf_t *elf, void *maped_file)
{
	elf->addr = maped_file;
	elf->ehdr = maped_file;
	if (!elf_validate_format(elf))
		return (RETURN_ERROR);
	return (0);
}
