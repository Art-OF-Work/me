#include <ctype.h>
#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @format: the format string
 * @i: pointer to the index in format
 * @list: list of arguments
 *
 * Return: the precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			(*i)++;
		}
		else if (isdigit(format[*i]))
		{
			precision = 0;
			while (isdigit(format[*i]))
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	return (precision);
}
