#include <stdarg.h>

/**
 * print_hexadecimal - prints a hexadecimal number
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	unsigned int n = va_arg(types, unsigned int);

	if (size == 1)
		n = (unsigned long int) n;
	else if (size == -1)
		n = (unsigned short int) n;

	count += print_hexa(n, buffer, flags, width, precision, size, 0);

	return (count);
}
