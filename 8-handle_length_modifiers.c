#include "main.h"

/**
 * handle_length_modifiers - Handle length modifiers
 * for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @length_modifier: Pointer to the length modifier ('l', 'h', or '\0')
 *
 * Return: The number of characters processed
 */
int handle_length_modifiers(const char *format, int i, char *length_modifier)
{
	while (format[i] == 'l' || format[i] == 'h')
	{
		if (format[i] == 'l' && *length_modifier != 'h')
			*length_modifier = 'l';
		else if (format[i] == 'h' && *length_modifier != 'l')
			*length_modifier = 'h';
		i++;
	}
	return (i);
}
