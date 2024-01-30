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
			buffer[ind] = map_to[n % 16];
			n /= 16;
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
