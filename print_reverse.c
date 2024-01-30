#include "main.h"
/**
 * print_reverse - prints a string in reverse
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	int len = strlen(str);

	for (int i = len - 1; i >= 0; i--)
		count += write(1, &str[i], 1);

	return (count);
}
