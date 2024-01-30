#include <stdarg.h>
#include "main.h"

/**
 * print_octal - prints an octal number
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	unsigned int n = va_arg(types, unsigned int);

	if (size == 1)
		n = (unsigned long int) n;
	else if (size == -1)
		n = (unsigned short int) n;

	if (n == 0)
	{
		buffer[0] = '0';
		int ind = 0;
		count += write_unsgnd(0, ind, buffer, flags, width, precision, size);
	}
	else
	{
		int ind = -1;

		while (n > 0)
		{
			ind++;
			buffer[ind] = (n % 8) + '0';
			n /= 8;
		}

		if (flags & F_HASH && precision != 0)
		{
			ind++;
			buffer[ind] = '0';
		}

		count += write_unsgnd(0, ind, buffer, flags, width, precision, size);
	}

	return (count);
}
