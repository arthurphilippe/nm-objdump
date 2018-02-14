/*
** EPITECH PROJECT, 2018
** nm
** File description:
** symbols
*/

#include <stddef.h>
#include "nmobjdump.h"

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

elf_symbol_t *get_symbol_list(elf_t *elf)
{
	elf_symbol_t *list = NULL;
	size_t idx_symtab = 0;
	Elf64_Shdr *sh_symtab;
	Elf64_Sym *symtab;

	get_next_symtab(elf, &sh_symtab, &symtab, &idx_symtab);
	while (symtab) {
		list_symbols_from_systab(elf, sh_symtab, symtab, &list);
		get_next_symtab(elf, &sh_symtab, &symtab, &idx_symtab);
	}
	sort_symbol_list(&list);
	return (list);
}
