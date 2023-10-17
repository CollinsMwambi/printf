#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character
 * @args: The va_list containing the character
 * @buffer: The buffer for output (if needed)
 * @buffer_index: The index of the buffer (if needed)
 *
 * Return: Number of characters printed
 */

int print_char(va_list args, char *buffer, int *buffer_index)
{
	(void)buffer;
	(void)buffer_index;
	return (_putchar(va_arg(args, int)));
}
