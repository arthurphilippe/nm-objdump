/*
** EPITECH PROJECT, 2018
** nm
** File description:
** type
*/

#include "nmobjdump.h"
#include "symbol_is_from_section.h"

char type_functor_wv(Elf64_Sym *sym)
{
	if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
		if (!sym->st_value)
			return (ELF64_ST_TYPE(sym->st_info)
				== STT_OBJECT ? 'v' : 'w');
		return (ELF64_ST_TYPE(sym->st_info)
			== STT_OBJECT ? 'V' : 'W');
	}
	return (0);
}

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

char type_functor_d(elf_t *elf, Elf64_Sym *sym)
{
	if (ELF64_ST_TYPE(sym->st_info) == STT_OBJECT
		|| ELF64_ST_TYPE(sym->st_info) == STT_NOTYPE
		|| symbol_is_from_section(sym, elf, ".data")
		|| symbol_is_from_section(sym, elf, ".data1"))
		return ('d');
	return (0);
}


char type_symbol(elf_t *elf, Elf64_Sym *sym)
{
	char ret;

	if (sym->st_shndx == SHN_ABS)
		return (ELF64_ST_BIND(sym->st_info)
			== STB_LOCAL ? 'a' : 'a' - 32);
	else if ((ret = type_functor_wv(sym))
			|| (ret = type_functor_cun(elf, sym)))
		return (ret);
	else if ((ret = type_functor_btr(elf, sym))
			|| (ret = type_functor_d(elf, sym)))
		return (ELF64_ST_BIND(sym->st_info)
			== STB_LOCAL ? ret : ret - 32);
	return ('?');
}
