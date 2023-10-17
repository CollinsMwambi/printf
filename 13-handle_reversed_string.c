#include "main.h"

/**
 * handle_custom_specifiers - Handle custom conversion specifiers
 * @args: The va_list of arguments
 * @buffer: The output buffer
 * @buffer_index: The current index in the output buffer
 * @specifier: The custom specifier character
 *
 * Return: The number of characters processed
 */
int handle_custom_specifiers(va_list args, char *buffer, int *buffer_index, char specifier)
{
	int count = 0;

	int len, i;

	if (specifier == 'r')
	{
		char *str = va_arg(args, char *);

		if (str != NULL)
		{
			len = 0;

			while (str[len] != '\0')
				len++;
			for (i = len - 1; i >= 0; i--)
				buffer[(*buffer_index)++] = str[i];

			count += len;
		}
	}

	return (count);
}

