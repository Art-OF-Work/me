#include <ctype.h>
#include "main.h"

/**
 * get_width - gets the width from the format string
 * @format: the format string
 * @i: pointer to the index in format
 * @list: list of arguments
 *
 * Return: the width
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	else if (isdigit(format[*i]))
	{
		while (isdigit(format[*i]))
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}

	return (width);
}
