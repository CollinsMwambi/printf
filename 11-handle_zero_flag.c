#include "main.h"

/**
 * handle_zero_flag - Handle the '0' flag character
 * for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @zero_flag: Pointer to the zero flag (1 if active, 0 if not)
 *
 * Return: The number of characters processed
 */
int handle_zero_flag(const char *format, int i, int *zero_flag)
{
	if (format[i] == '0')
	{
		*zero_flag = 1;
		i++;
	}

	return (i);
}
