#include "main.h"

/**
 * print_char - prints a character
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	char c = va_arg(types, int);

	count += handle_write_char(c, buffer, flags, width, precision, size);

	return (count);
}
