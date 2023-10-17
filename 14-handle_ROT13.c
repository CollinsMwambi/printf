#include "main.h"

/**
 * handle_rot13 - Apply ROT13 encryption to a string
 * @str: The input string to be ROT13 encrypted
 * @len: The length of the string
 */
void handle_rot13(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		char c = str[i];

		if ((c >= 'a' && c <= 'z'))
		{
			if (c >= 'a' + 13)
				str[i] = c - 13;
			else
				str[i] = c + 13;
		}
		else if ((c >= 'A' && c <= 'Z'))
		{
			if (c >= 'A' + 13)
				str[i] = c - 13;
			else
				str[i] = c + 13;
		}
	}
}

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
	int count = 0, len = 0, i;

	if (specifier == 'r')
	{
		char *str = va_arg(args, char *);

		if (str != NULL)
		{
			while (str[len] != '\0')
				len++;
			for (i = len - 1; i >= 0; i--)
				buffer[(*buffer_index)++] = str[i];
			count += len;
		}
	}
	else if (specifier == 'R')
	{
		char *str = va_arg(args, char *);

		if (str != NULL)
		{
			while (str[len] != '\0')
				len++;

			handle_rot13(str, len);

			for (i = 0; i < len; i++)
				buffer[(*buffer_index)++] = str[i];
			count += len;
		}
	}
	return (count);
}


