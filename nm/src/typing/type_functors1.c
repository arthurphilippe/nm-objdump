/*
** EPITECH PROJECT, 2018
** nmobjdump
** File description:
** typing
*/

#include "nmobjdump.h"
#include "symbol_is_from_section.h"
#include "symbol_type_change_case.h"

char type_functor_common(elf_t *elf, Elf64_Sym *sym)
{
	(void) elf;
	if (sym->st_shndx == SHN_COMMON)
		return ('C');
	return (0);
}

char type_functor_undef(elf_t *elf, Elf64_Sym *sym)
{
	(void) elf;
	if (sym->st_shndx == SHN_UNDEF)
		return ('U');
	return (0);
}

char type_functor_debug(elf_t *elf, Elf64_Sym *sym)
{
	if (symbol_is_from_section(sym, elf, ".debug"))
		return ('N');
	return (0);
}

char type_functor_uninit(elf_t *elf, Elf64_Sym *sym)
{
	if (symbol_is_from_section(sym, elf, ".bss"))
		return (symbol_type_change_case(sym, 'b'));
	return (0);
}

char type_functor_text(elf_t *elf, Elf64_Sym *sym)
{
	if ((symbol_is_from_section(sym, elf, ".text")
			|| ELF64_ST_TYPE(sym->st_info) == STT_FUNC)
		|| (elf->sh_table[sym->st_shndx].sh_type == SHT_PROGBITS
			&& elf->sh_table[sym->st_shndx].sh_flags ==
				(SHF_ALLOC | SHF_EXECINSTR))
		|| elf->sh_table[sym->st_shndx].sh_type > SHT_DYNSYM)
		return (symbol_type_change_case(sym, 't'));
	return (0);
}

