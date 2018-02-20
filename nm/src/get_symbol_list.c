/*
** EPITECH PROJECT, 2018
** nm
** File description:
** symbols
*/

#include <stdlib.h>
#include <stddef.h>
#include "nmobjdump.h"

/*
** If the file is in 32bits format, the entired symtab is fitted into
** a 64bits symtab sctruct.
*/
static Elf64_Sym *get_fitted_symtab(Elf32_Sym *src, size_t count)
{
	size_t i = 0;
	Elf64_Sym *dest = malloc(sizeof(*dest) * count);

	while (i < count) {
		dest[i].st_name = src[i].st_name;
		dest[i].st_value = src[i].st_value;
		dest[i].st_size = src[i].st_size;
		dest[i].st_info = src[i].st_info;
		dest[i].st_other = src[i].st_other;
		dest[i].st_shndx = src[i].st_shndx;
		i += 1;
	}
	return (dest);
}

/*
** Uses this idx paramater to get the symtab that follows.
*/
static void get_next_symtab(elf_t *elf, Elf64_Shdr **sh_symtab,
				Elf64_Sym **symtab, size_t *idx)
{
	while (*idx < elf->ehdr->e_shnum) {
		if (elf->sh_table[*idx].sh_type == SHT_SYMTAB) {
			*sh_symtab = &elf->sh_table[*idx];
			*idx += 1;
			*symtab = (Elf64_Sym *)
				(elf->addr + (*sh_symtab)->sh_offset);
			return;
		}
		*idx += 1;
	}
	*sh_symtab = NULL;
	*symtab = NULL;
}

/*
** Handles the sorting will the list isn't sorted.
** It isn't clear how different versions of nm sort tho...
*/
void sort_symbol_list(elf_symbol_t **head)
{
	elf_symbol_t *curr;

	curr = *head;
	while (curr->next) {
		if (compare_and_swap_nodes(curr))
			curr = *head;
		else
			curr = curr->next;
	}
}

/*
** Handles the creation of the symbol list.
*/
elf_symbol_t *get_symbol_list(elf_t *elf)
{
	elf_symbol_t *list = NULL;
	size_t idx_symtab = 0;
	Elf64_Shdr *sh_symtab;
	Elf64_Sym *symtab;

	get_next_symtab(elf, &sh_symtab, &symtab, &idx_symtab);
	while (symtab) {
		if (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
			symtab = get_fitted_symtab((void *) symtab,
				sh_symtab->sh_size / sh_symtab->sh_entsize);
			list_symbols_from_systab(elf, sh_symtab, symtab, &list);
			free(symtab);
		}
		else
			list_symbols_from_systab(elf, sh_symtab, symtab, &list);
		get_next_symtab(elf, &sh_symtab, &symtab, &idx_symtab);
	}
	sort_symbol_list(&list);
	return (list);
}
