/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** elf compat
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "nmobjdump.h"

static void elf_cpy_header(Elf32_Ehdr *src, Elf64_Ehdr *dest)
{
	memcpy(dest->e_ident, src->e_ident, EI_NIDENT);
	dest->e_type = src->e_type;
	dest->e_machine = src->e_machine;
	dest->e_version = src->e_version;
	dest->e_version = src->e_version;
	dest->e_entry = src->e_entry;
	dest->e_phoff = src->e_phoff;
	dest->e_shoff = src->e_shoff;
	dest->e_flags = src->e_flags;
	dest->e_ehsize = src->e_ehsize;
	dest->e_phentsize = src->e_phentsize;
	dest->e_shnum = src->e_shnum;
	dest->e_shstrndx = src->e_shstrndx;
}

static Elf64_Shdr *elf_dup_sh_table(Elf32_Ehdr *src)
{
	size_t idx = 0;
	Elf32_Shdr *sht_src = (Elf32_Shdr *) (((char *) src) + src->e_shoff);
	Elf64_Shdr *sht_dest = malloc(sizeof(Elf64_Shdr) * src->e_shnum);

	if (!sht_dest) {
		perror("memory");
		return (sht_dest);
	}
	while (idx < src->e_shnum) {
		sht_dest[idx].sh_name = sht_src[idx].sh_name;
		sht_dest[idx].sh_type = sht_src[idx].sh_type;
		sht_dest[idx].sh_flags = sht_src[idx].sh_flags;
		sht_dest[idx].sh_addr = sht_src[idx].sh_addr;
		sht_dest[idx].sh_offset = sht_src[idx].sh_offset;
		sht_dest[idx].sh_size = sht_src[idx].sh_size;
		sht_dest[idx].sh_link = sht_src[idx].sh_link;
		sht_dest[idx].sh_info = sht_src[idx].sh_info;
		sht_dest[idx].sh_addralign = sht_src[idx].sh_addralign;
		sht_dest[idx].sh_entsize = sht_src[idx].sh_entsize;
		idx += 1;
	}
	return (sht_dest);
}

int elf_populate_32bits(elf_t *elf)
{
	Elf32_Ehdr *src = (Elf32_Ehdr *) elf->addr;
	Elf64_Ehdr *dest = malloc(sizeof(Elf64_Ehdr));

	if (!dest) {
		perror("memory");
		return (RETURN_ERROR);
	}
	elf_cpy_header(src, dest);
	elf->sh_table = elf_dup_sh_table(src);
	return ((elf->sh_table) ? RETURN_OK : RETURN_ERROR);
}
