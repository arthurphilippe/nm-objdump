/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_byte
*/

#ifndef PRINT_BYTE_H_
	#define PRINT_BYTE_H_

	#include <stdio.h>
	#include <ctype.h>

inline static char print_byte(char byte)
{
	if (byte > 0) {
		printf("%02x", byte);
		// dprintf(2, "%d -> %02x\n", byte, byte);
	} else if (byte == 0) {
		printf("00");
		// dprintf(2, "%d -> 00\n", byte);
	} else {
		// printf("%02x", -byte);
		printf("--");
	}
	return ((!isprint(byte)) ? '.' : byte);
}

#endif /* !PRINT_BYTE_H_ */
