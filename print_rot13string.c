#include "main.h"

/**
 * print_rot13string - prints a string in rot13
 * @types: list of arguments
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			count += write(1, &"NOPQRSTUVWXYZABCDEFGHIJKLM"[*str - 'A'], 1);
		else if (*str >= 'a' && *str <= 'z')
			count += write(1, &"nopqrstuvwxyzabcdefghijklm"[*str - 'a'], 1);
		else
			count += write(1, str, 1);

		str++;
	}

	return (count);
}
