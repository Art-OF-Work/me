#include "main.h"

/**
 * write_pointer - writes a pointer to a buffer
 * @buffer: the buffer to write to
 * @ind: index of the buffer
 * @length: length of the buffer
 * @width: width of format
 * @flags: flags for formatting
 * @padd: padding character
 * @extra_c: extra character to write
 * @padd_start: flag indicating when to start padding
 *
 * Return: the count of characters written
 */
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
	int count = 0;

	width -= 2;

	if (!(flags & F_MINUS) && padd_start == 0)
		count += write_padding(width - length, padd);

	count += write(1, "0x", 2);

	if (!(flags & F_MINUS) && padd_start == 1)
		count += write_padding(width - length, padd);

	if (extra_c)
		count += write(1, &extra_c, 1);

	count += write(1, buffer, length);

	if (flags & F_MINUS)
		count += write_padding(width - length, padd);

	return (count);
}
