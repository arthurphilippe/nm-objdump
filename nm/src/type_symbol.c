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

/*
** Types a given symbols using all the typing functors at disposal.
*/
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
