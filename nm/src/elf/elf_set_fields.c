/*
** EPITECH PROJECT, 2018
** nm
** File description:
** set elf fields
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "nm.h"

/*
** Comes after the setting the sh table.
** Sets the sh_string_table in the elf object given.
*/
static int elf_populate_shstrtab(elf_t *elf)
{
	Elf64_Half shstrndx = elf->ehdr->e_shstrndx;

	if (shstrndx == SHN_UNDEF) {
		dprintf(STDERR_FILENO, "Cannot get shstrndx\n");
		return (RETURN_ERROR);
	}
	elf->sh_string_table = ((char *) elf->addr) +
		elf->sh_table[shstrndx].sh_offset;
	return (RETURN_OK);
}

/*
** Comes after setting the shstrtable
** Sets the string_table in the elf object given.
*/
static int elf_populate_strtab(elf_t *elf)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (strcmp(&elf->sh_string_table[elf->sh_table[i].sh_name],
				".strtab") == 0) {
			elf->string_table = (char *) elf->sh_table[i].sh_offset;
			return (RETURN_OK);
		}
		i += 1;
	}
	dprintf(STDERR_FILENO, "Failed to find string table\n");
	return (RETURN_ERROR);
}

/*
** Populates the given elf object using the maped_file passed as param.
*/
int elf_set_fields(elf_t *elf, void *maped_file)
{
	elf->addr = maped_file;
	elf->ehdr = maped_file;
	if (!elf_validate_format(elf)) {
		dprintf(STDERR_FILENO, "File format not recognized\n");
		return (RETURN_ERROR);
	}
	elf->sh_table = (Elf64_Shdr *) (elf->addr + elf->ehdr->e_shoff);
	if (elf_populate_shstrtab(elf) || elf_populate_strtab(elf))
		return (RETURN_ERROR);
	return (RETURN_OK);
}
