#include <stdarg.h>
#include "main.h"

/**
 * print_percent - prints a percent sign
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;

	if (!(flags & F_MINUS))
		count += write_padding(width - 1, ' ');

	count += write(1, "%", 1);

	if (flags & F_MINUS)
		count += write_padding(width - 1, ' ');

	return (count);
}
