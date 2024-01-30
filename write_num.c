#include "main.h"

/**
 * write_num - writes a number to a buffer
 * @ind: index of the buffer
 * @buffer: the buffer to write to
 * @flags: flags for formatting
 * @width: width of format
 * @prec: precision of format
 * @length: length of format
 * @padd: padding character
 * @extra_c: extra character to write
 *
 * Return: the count of characters written
 */
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
	int count = 0;
	int len = (ind >= 0) ? ind + 1 : 0;

	if (prec == 0 && buffer[ind] == '0')
		ind = -1;

	if (extra_c)
		width--;

	if (flags & F_ZERO && prec < 0)
	{
		prec = width;
		width = 0;
	}

	if (prec > len)
		width -= prec;
	else
		width -= len;

	if (!(flags & F_MINUS))
		count += write_padding(width, padd);

	if (extra_c)
		count += write(1, &extra_c, 1);

	count += write_padding(prec - len, '0');
	count += write(1, buffer, len);

	if (flags & F_MINUS)
		count += write_padding(width, padd);

	return (count);
}
