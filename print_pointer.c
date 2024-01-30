#include "main.h"

/**
 * print_pointer - prints a pointer address
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	void *p = va_arg(types, void *);

	if (p == NULL)
	{
		buffer[0] = '0';
		int ind = 0;
		count += write_pointer(buffer, ind, 1, width, flags, ' ', 0, 0);
	}
	else
	{
		unsigned long int n = (unsigned long int) p;
		int ind = -1;

		while (n > 0)
		{
			ind++;
			buffer[ind] = "0123456789abcdef"[n % 16];
			n /= 16;
		}

		count += write_pointer(buffer, ind, ind + 1, width, flags, ' ', 0, 0);
	}

	return (count);
}
