#include "main.h"

/**
 * write_number - writes a number to a buffer
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
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	int len = (ind >= 0) ? ind + 1 : 0;

	if (precision == 0 && buffer[ind] == '0')
		ind = -1;

	if (is_negative || flags & (F_PLUS | F_SPACE))
		width--;

	if (flags & F_ZERO && precision < 0)
	{
		precision = width;
		width = 0;
	}

	if (precision > len)
		width -= precision;
	else
		width -= len;

	if (!(flags & F_MINUS))
		count += write_padding(width, ' ');

	if (is_negative)
		count += write(1, "-", 1);
	else if (flags & F_PLUS)
		count += write(1, "+", 1);
	else if (flags & F_SPACE)
		count += write(1, " ", 1);

	count += write_padding(precision - len, '0');
	count += write_num(ind, buffer);

	if (flags & F_MINUS)
		count += write_padding(width, ' ');

	return (count);
}
