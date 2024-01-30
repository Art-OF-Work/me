#include "main.h"
#include <string.h>
/**
 * get_flags - gets the flags from the format string
 * @format: the format string
 * @i: pointer to the index in format
 *
 * Return: the flags
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	const char *flag_chars = "-+0# ";
	const int flag_masks[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

	while (format[*i])
	{
		char *found = strchr(flag_chars, format[*i]);

		if (found)
		{
			flags |= flag_masks[found - flag_chars];
		}
		else
		{
			break;
		}
		(*i)++;
	}

	return (flags);
}
