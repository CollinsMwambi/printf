#include "main.h"

/**
 * print_custom_string - Print a string with special handling for non-printable characters
 * @args: The va_list containing the string
 * @buffer: The output buffer
 * @buffer_index: The index in the buffer
 *
 * Return: Number of characters printed
 */

int print_custom_string(va_list args, char *buffer, int *buffer_index)
{
	char *str = va_arg(args, char *);

	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count])
	{
		if (str[count] < 32 || str[count] >= 127)
		{
			buffer[(*buffer_index)++] = '\\';
			buffer[(*buffer_index)++] = 'x';
			buffer[(*buffer_index)++] = (str[count] / 16 < 10) ? (str[count] / 16 + '0') : (str[count] / 16 - 10 + 'A');
			buffer[(*buffer_index)++] = (str[count] % 16 < 10) ? (str[count] % 16 + '0') : (str[count] % 16 - 10 + 'A');
			count++;
		}
		else
		{
			buffer[(*buffer_index)++] = str[count];
			count++;
		}
	}

	return (count);
}
