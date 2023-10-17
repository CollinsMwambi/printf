#include "main.h"

/**
 * handle_flags - Handle flag characters for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @plus_flag: Pointer to the plus flag (1 if active, 0 if not)
 * @space_flag: Pointer to the space flag (1 if active, 0 if not)
 * @hash_flag: Pointer to the hash flag (1 if active, 0 if not)
 *
 * Return: The number of characters processed
 */

int handle_flags(const char *format, int i, int *plus_flag, int *space_flag, int *hash_flag)
{
	while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
	{
		if (format[i] == '+')
			*plus_flag = 1;
		else if (format[i] == ' ')
			*space_flag = 1;
		else if (format[i] == '#')
			*hash_flag = 1;
		i++;
	}

	return (i);
}
