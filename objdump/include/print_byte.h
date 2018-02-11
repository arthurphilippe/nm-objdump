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

inline static char print_byte(unsigned char byte)
{
	if (byte > 0) {
		printf("%02x", byte);
	} else if (byte == 0) {
		printf("00");
	}
	return ((!isprint(byte)) ? '.' : byte);
}

#endif /* !PRINT_BYTE_H_ */
