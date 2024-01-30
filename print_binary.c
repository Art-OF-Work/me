#include "main.h"

/**
 * print_binary - prints a binary number
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	unsigned int n = va_arg(types, unsigned int);

	if (size == 1)
		n = (unsigned long int) n;
	else if (size == -1)
		n = (unsigned short int) n;

	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		unsigned int power = 1;

		while (power <= n / 2)
			power *= 2;

		while (power > 0)
		{
			if (power <= n)
			{
				count += write(1, "1", 1);
				n -= power;
			}
			else
				count += write(1, "0", 1);

			power /= 2;
		}
	}

	return (count);
}
