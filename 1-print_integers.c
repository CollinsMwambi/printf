#include "main.h"

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */

int print_int(va_list args)
{
	int num = va_arg(args, int);

	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}

	if (num / 10)
		count += print_int_recursive(num / 10);

	_putchar('0' + (num % 10));
	return (count + 1);
}

/**
 * print_int_recursive - Helper function to print an integer
 * @num: The integer to print
 *
 * Return: Number of characters printed
 */
int print_int_recursive(int num)
{
	int count = 0;

	if (num / 10)
		count += print_int_recursive(num / 10);

	_putchar('0' + (num % 10));
	return (count + 1);
}
