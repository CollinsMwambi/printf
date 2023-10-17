#include "main.h"

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer
 * @buffer: The output buffer
 * @buffer_index: The index in the buffer
 *
 * Return: Number of characters printed
 */

int print_int(va_list args, char *buffer, int *buffer_index)
{
	int num = va_arg(args, int);

	int count = 0;

	if (num < 0)
	{
		_putchar('-', buffer, buffer_index);
		num = -num;
		count++;
	}

	if (num / 10)
		count += print_int_recursive(num / 10, buffer, buffer_index);;

	_putchar('0' + (num % 10), buffer, buffer_index);
	return (count + 1);
}

/**
 * print_int_recursive - Helper function to print an integer
 * @num: The integer to print
 *
 * Return: Number of characters printed
 */
int print_int_recursive(int num, char *buffer, int *buffer_index)
{
	int count = 0;

	if (num / 10)
		count += print_int_recursive(num / 10, buffer, buffer_index);

	_putchar('0' + (num % 10), buffer, buffer_index);
	return (count + 1);
}
