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

inline char print_byte(char byte)
{
	if (byte < 0)
		printf("00");
	else
		printf("%02x", byte);
	return ((!isprint(byte)) ? '.' : byte);
}

#endif /* !PRINT_BYTE_H_ */
