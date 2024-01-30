#include "main.h"

/**
 * handle_write_char - writes a character to a buffer
 * @c: the character to write
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	int padding = width - 1;

	if (width > 1)
	{
		if (flags & F_MINUS)
		{
			buffer[count++] = c;
			while (padding--)
				buffer[count++] = ' ';
		}
		else if (flags & F_ZERO)
		{
			while (padding--)
				buffer[count++] = '0';
			buffer[count++] = c;
		}
		else
		{
			while (padding--)
				buffer[count++] = ' ';
			buffer[count++] = c;
		}
	}
	else
	{
		buffer[count++] = c;
	}

	write(1, buffer, count);

	return (count);
}
