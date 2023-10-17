#include "main.h"

/**
 * handle_field_width - Handle field width for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @field_width: Pointer to the field width
 *
 * Return: The number of characters processed
 */
int handle_field_width(const char *format, int i, int *field_width)
{
	int width = 0;

	while (format[i] >= '0' && format[i] <= '9')
	{
		width = width * 10 + (format[i] - '0');
		i++;
	}

	if (width > 0)
		*field_width = width;

	return (i);
}
