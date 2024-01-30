#include "main.h"

/**
 * write_unsgnd - writes an unsigned number to a buffer
 * @is_negative: flag indicating if the number is negative
 * @ind: index of the buffer
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @precision: precision of format
 * @size: size of buffer
 *
 * Return: the count of characters written
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;

	if (flags & F_HASH && buffer[ind] != '0')
		width -= 2;

	count += write_number(is_negative, ind, buffer, flags, width, precision, size);

	if (flags & F_HASH && buffer[ind] != '0')
		count += write(1, (flags & S_LONG) ? "0X" : "0x", 2);

	return (count);
}
