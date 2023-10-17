#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character
 * @args: The va_list containing the character
 *
 * Return: Number of characters printed
 */

int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
