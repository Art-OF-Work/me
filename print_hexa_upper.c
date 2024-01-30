#include <stdarg.h>
#include "main.h"

/**
 * print_hexa_upper - prints a hexadecimal number in uppercase
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	unsigned int n = va_arg(types, unsigned int);

	if (size == 1)
		n = (unsigned long int) n;
	else if (size == -1)
		n = (unsigned short int) n;

	count += print_hexa(n, buffer, flags, width, precision, size, 1);

	return (count);
}
