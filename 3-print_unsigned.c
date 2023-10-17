#include "main.h"
/**
 * print_unsigned_recursive - Helper function to print an unsigned integer
 * @num: The unsigned integer to print
 *
 * Return: Number of characters printed
 *
 */
int print_unsigned_recursive(unsigned int num, char *buffer, int *buffer_index)
{
	int count = 0;

	if (num / 10)
		count += print_unsigned_recursive(num / 10, buffer, buffer_index);

	_putchar('0' + (num % 10), buffer, buffer_index);
	return (count + 1);
}
/**
 * print_unsigned - Print an unsigned integer
 * @args: The va_list containing the unsigned integer
 *
 * Return: Number of characters printed
 */

int print_unsigned(va_list args, char *buffer, int *buffer_index)
{
	unsigned int num = va_arg(args, unsigned int);

	int count = 0;

	if (num / 10)
		count += print_unsigned_recursive(num / 10, buffer, buffer_index);

	_putchar('0' + (num % 10), buffer, buffer_index);
	return (count + 1);

}
