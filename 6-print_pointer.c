#include "main.h"

/**
 * print_pointer - Print a pointer address
 * @args: The va_list containing the pointer
 * @buffer: The output buffer
 * @buffer_index: The index in the buffer
 *
 * Return: Number of characters printed
 */

int print_pointer(va_list args, char *buffer, int *buffer_index)
{
	void *ptr = va_arg(args, void *);

	unsigned long int address = (unsigned long int)ptr;

	char hex_digits[] = "0123456789ABCDEF";

	int count = 0;

	buffer[(*buffer_index)++] = '0';
	buffer[(*buffer_index)++] = 'x';

	if (address == 0)
	{
		buffer[(*buffer_index)++] = '0';
		count++;
	}
	else
	{
		while (address > 0)
		{
			buffer[(*buffer_index)++] = hex_digits[address % 16];
			address /= 16;
			count++;
		}
	}
	return (count + 2);
}
