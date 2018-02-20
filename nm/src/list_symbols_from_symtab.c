/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** symbols from symtab
*/

#include <stddef.h>
#include "nmobjdump.h"
#include "symbol_is_printable.h"

/*
** Gather the symbols from the current symtab
*/
void list_symbols_from_systab(elf_t *elf, Elf64_Shdr *sh_symtab,
				Elf64_Sym *symtab, elf_symbol_t **head)
{
	elf_symbol_t *curr;
	size_t symbol_count = sh_symtab->sh_size / sh_symtab->sh_entsize;
	size_t i = 0;

	while (i < symbol_count) {
		if (symbol_is_printable(elf, &symtab[i])) {
			curr = new_node(symtab[i].st_value,
					&(elf->string_table[symtab[i].st_name]),
					type_symbol(elf, &symtab[i]));
			symbol_list_pushback(head, curr);
		}
		i += 1;
	}
}
