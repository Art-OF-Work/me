#include <stdarg.h>

/**
 * print_unsigned - prints an unsigned integer
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
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
			buffer[ind] = (n % 10) + '0';
			n /= 10;
		}

		count += write_unsgnd(0, ind, buffer, flags, width, precision, size);
	}

	return (count);
}