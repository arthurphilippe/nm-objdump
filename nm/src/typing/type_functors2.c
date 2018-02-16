/*
** EPITECH PROJECT, 2018
** nmobjdump
** File description:
** typing
*/

#include "nmobjdump.h"
#include "symbol_is_from_section.h"
#include "symbol_type_change_case.h"

char type_functor_absolute(elf_t *elf, Elf64_Sym *sym)
{
	(void) elf;
	if (sym->st_shndx == SHN_ABS)
		return (symbol_type_change_case(sym, 'a'));
	return (0);
}

char type_functor_rom(elf_t *elf, Elf64_Sym *sym)
{
	if (elf->sh_table[sym->st_shndx].sh_type == SHT_PROGBITS
			&& elf->sh_table[sym->st_shndx].sh_flags == SHF_ALLOC)
		return (symbol_type_change_case(sym, 'r'));
	return (0);
}

char type_functor_init(elf_t *elf, Elf64_Sym *sym)
{
	if (ELF64_ST_TYPE(sym->st_info) == STT_OBJECT
		|| ELF64_ST_TYPE(sym->st_info) == STT_NOTYPE
		|| symbol_is_from_section(sym, elf, ".data")
		|| symbol_is_from_section(sym, elf, ".data1"))
		return (symbol_type_change_case(sym, 'd'));
	return (0);
}

char type_functor_weak(elf_t *elf, Elf64_Sym *sym)
{
	(void) elf;
	if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
		if (!sym->st_value)
			return (ELF64_ST_TYPE(sym->st_info)
				== STT_OBJECT ? 'v' : 'w');
		return (ELF64_ST_TYPE(sym->st_info)
			== STT_OBJECT ? 'V' : 'W');
	}
	return (0);
}
