#include "main.h"

/**
 * print_octal - Print an integer in octal format
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */

int print_octal(va_list args, char *buffer, int *buffer_index)
{
	unsigned int num = va_arg(args, unsigned int);

	int count = 0;

	int octal[32];

	int i = 0;

	if (num == 0)
	{
		_putchar('0', buffer, buffer_index);
		return (1);
	}

	while (num > 0)
	{
		octal[i] = num % 8;
		num = num / 8;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar('0' + octal[i], buffer, buffer_index);
		count++;
	}
	return (count);
}
