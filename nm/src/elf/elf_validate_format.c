/*
** EPITECH PROJECT, 2018
** nm
** File description:
** validate format
*/

#include "nmobjdump.h"

int elf_validate_format(elf_t *elf)
{
	char *e_ident = (char *) elf->ehdr->e_ident;

	return (e_ident[EI_MAG0] == ELFMAG0
		&& e_ident[EI_MAG1] == ELFMAG1
		&& e_ident[EI_MAG2] == ELFMAG2
		&& e_ident[EI_MAG3] == ELFMAG3);
}
