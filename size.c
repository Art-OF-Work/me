#include <stdio.h>

/**
 * get_size - gets the size from the format string
 * @format: the format string
 * @i: pointer to the index in format
 *
 * Return: the size
 */
int get_size(const char *format, int *i)
{
	int size = 0;

	if (format[*i] == 'l' || format[*i] == 'h')
	{
		size = (format[*i] == 'l') ? 1 : -1;
		(*i)++;
	}

	return (size);
}
