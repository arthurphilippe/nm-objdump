/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** target
*/

#include "nmobjdump.h"
#include "get_target_arch.h"

const arch_map_t ARCHS[] = {
	{EM_NONE, "Unknown"},
	{EM_M32, "WE 32100"},
	{EM_SPARC, "SPARC"},
	{EM_386, "i386"},
	{EM_68K, "m68k"},
	{EM_88K, "m88k"},
	{EM_860, "i860"},
	{EM_MIPS, "MIPS RS3000"},
	{EM_PARISC, "hp/pa"},
	{EM_SPARC32PLUS, "SPARC +"},
	{EM_PPC, "PowerPC"},
	{EM_PPC64, "PowerPC64"},
	{EM_S390, "IBM S/390"},
	{EM_ARM, "ARM"},
	{EM_SH, "superH"},
	{EM_SPARCV9, "SPARCV9"},
	{EM_IA_64, "IA-64"},
	{EM_X86_64, "i386"},
	{EM_VAX, "VAX"}
};

/*
** Returns a const string containing the name of the current arch.
*/
const char *get_target_arch(int machine)
{
	int i = 0;

	while (i < 20) {
		if (machine == ARCHS[i].type)
			return (ARCHS[i].name);
		i += 1;
	}
	return (ARCHS[0].name);
}
