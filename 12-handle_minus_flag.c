#include "main.h"

/**
 * handle_minus_flag - Handle the '-' flag character for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @minus_flag: Pointer to the minus flag (1 if active, 0 if not)
 *
 * Return: The number of characters processed
 */
int handle_minus_flag(const char *format, int i, int *minus_flag)
{
	if (format[i] == '-')
	{
		*minus_flag = 1;
		i++;
	}
	
	return (i);
}
