#include "main.h"

/**
 * print_binary - Print an integer in binary format
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int count, binary[32], i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar('0' + binary[i]);
		count++;
	}

	return (count);
}
