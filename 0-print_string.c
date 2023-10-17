#include "main.h"

/**
 * print_string - Print a string
 * @args: The va_list containing the string
 *
 * Return: Number of characters printed
 */


int print_string(va_list args, char *buffer, int *buffer_index)
{
	char *str = va_arg(args, char *);

	int count = 0;

	(void)buffer;
	(void)buffer_index;

	if (str == NULL)
		str = "(null)";

	while (str[count])
	{
		_putchar(str[count]);
		count++;
	}

	return (count);
}

