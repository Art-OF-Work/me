#include <stdarg.h>
#include "main.h"

/**
 * print_hexa - prints a hexadecimal number
 * @types: list of arguments
 * @map_to: mapping to hexadecimal characters
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @flag_ch: flag character for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int count = 0;
	unsigned int m = va_arg(types, unsigned int);

	if (size == 1)
		m = (unsigned long int) m;
	else if (size == -1)
		m = (unsigned short int) m;

	if (n == 0)
	{
		buffer[0] = '0';
		int ind = 0;
		count += write_unsgnd(0, ind, buffer, flags, width, precision, size);
	}
	else
	{
		int ind = -1;

		while (m > 0)
		{
			ind++;
			buffer[ind] = map_to[m % 16];
			m /= 16;
		}

		if (flags & F_HASH && flag_ch != ' ')
		{
			ind++;
			buffer[ind] = flag_ch;
			ind++;
			buffer[ind] = '0';
		}

		count += write_unsgnd(0, ind, buffer, flags, width, precision, size);
	}

	return (count);
}
