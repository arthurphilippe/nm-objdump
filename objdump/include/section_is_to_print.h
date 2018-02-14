/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** section is to print
*/

#ifndef SECTION_IS_TO_PRINT_H_
	#define SECTION_IS_TO_PRINT_H_

	#include <stddef.h>
	#include <string.h>
	#include "nmobjdump.h"

inline static int section_is_to_print(elf_t *elf, size_t i)
{
	return (elf->sh_table[i].sh_type != SHT_SYMTAB
		&& elf->sh_table[i].sh_type != SHT_NOBITS
		&& (elf->sh_table[i].sh_type != SHT_STRTAB ||
			elf->sh_table[i].sh_flags == SHF_ALLOC)
		&& (elf->ehdr->e_type != ET_REL
			|| elf->sh_table[i].sh_type != SHT_RELA)
		&& elf->sh_table[i].sh_size
		&& elf->sh_string_table[elf->sh_table[i].sh_name]);
}

#endif /* !SECTION_IS_TO_PRINT_H_ */
