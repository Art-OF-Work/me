#include "main.h"
#include <stdarg.h>
#include <ctype.h>

/**
 * print_non_printable - prints non-printable characters in a string
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (isprint(*str))
			count += write(1, str, 1);
		else
		{
			count += write(1, "\\", 1);
			count += write(1, "x", 1);

			char hex[3];
			sprintf(hex, "%02x", *str);

			count += write(1, hex, 2);
		}

		str++;
	}

	return (count);
}
