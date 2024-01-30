#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * print_string - prints a string
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	int len = strlen(str);

	if (precision >= 0 && precision < len)
		len = precision;

	if (!(flags & F_MINUS))
		count += write_padding(width - len, ' ');

	count += write(1, str, len);

	if (flags & F_MINUS)
		count += write_padding(width - len, ' ');

	return (count);
}
