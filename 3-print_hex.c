#include "main.h"

/**
 * print_hex - Print an integer in hexadecimal format (lowercase)
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */

int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int count = 0, hex[32], i = 0;

	if (num == 0)
	{
		_putchar('0', NULL, NULL);
		return (1);
	}

	while (num > 0)
	{
		hex[i] = num % 16;
		num = num / 16;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		if (hex[i] < 10)
			_putchar('0' + hex[i], NULL, NULL);
		else
			_putchar('a' + hex[i] - 10, NULL, NULL);

		count++;
	}

	return (count);
}

