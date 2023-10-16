#include "main.h"

/**
 * print_integer - Helper function to print an integer.
 * @num: The integer to print.
 * @printed: The count of characters printed so far.
 * Return: The updated count of characters printed.
 */
int print_integer(int num, int printed)
{
	int digits = 0;

	int temp = num;

	int i, digit, pow10;

	if (num < 0)
	{
		printed += _putchar('-');
		num = -num;
		temp = num;
	}

	do {
		digits++;
		temp /= 10;
	} while (temp != 0);

	while (digits > 0)
	{
		pow10 = 1;
		for (i = 1; i < digits; i++)
			pow10 *= 10;
		digit = num / pow10;
		printed += _putchar(digit + '0');
		num -= digit * pow10;
		digits--;
	}
	return (printed);
}


/**
 * printf_integer - Print an integer.
 * @args: The va_list containing the integer to print.
 * @printed: The count of characters printed so far.
 * Return: The updated count of characters printed.
 */
int printf_integer(va_list args, int printed)
{
	int num = va_arg(args, int);

	return (print_integer(num, printed));
}
