/*
** EPITECH PROJECT, 2018
** nm
** File description:
** type
*/

#include "nmobjdump.h"
#include "symbol_is_from_section.h"
#include "type_functors.h"

char (*const TYPE_FUNCTORS[]) (elf_t *elf, Elf64_Sym *sym) = {
	type_functor_absolute,
	type_functor_weak,
	type_functor_common,
	type_functor_undef,
	type_functor_debug,
	type_functor_uninit,
	type_functor_text,
	type_functor_rom,
	type_functor_init,
	NULL,
};

char type_functor_cun(elf_t *elf, Elf64_Sym *sym)
{
	if (sym->st_shndx == SHN_COMMON)
		return ('C');
	else if (sym->st_shndx == SHN_UNDEF)
		return ('U');
	else if (symbol_is_from_section(sym, elf, ".debug"))
		return ('N');
	return (0);
}

char type_functor_btr(elf_t *elf, Elf64_Sym *sym)
{
	if (symbol_is_from_section(sym, elf, ".bss"))
		return ('b');
	else if ((symbol_is_from_section(sym, elf, ".text")
			|| ELF64_ST_TYPE(sym->st_info) == STT_FUNC)
		|| (elf->sh_table[sym->st_shndx].sh_type == SHT_PROGBITS
			&& elf->sh_table[sym->st_shndx].sh_flags ==
				(SHF_ALLOC | SHF_EXECINSTR))
		|| elf->sh_table[sym->st_shndx].sh_type > SHT_DYNSYM)
		return ('t');
	else if (elf->sh_table[sym->st_shndx].sh_type == SHT_PROGBITS
			&& elf->sh_table[sym->st_shndx].sh_flags == SHF_ALLOC)
		return ('r');
	return (0);
}

char type_symbol(elf_t *elf, Elf64_Sym *sym)
{
	char ret;
	size_t i = 0;

	while (TYPE_FUNCTORS[i]) {
		ret = TYPE_FUNCTORS[i](elf, sym);
		if (ret)
			return (ret);
		i += 1;
	}
	return ('?');
}
