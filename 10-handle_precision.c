#include "main.h"

/**
 * handle_precision - Handle precision for non-custom conversion specifiers
 * @format: The format string
 * @i: The current index in the format string
 * @precision: Pointer to the precision
 *
 * Return: The number of characters processed
 */
int handle_precision(const char *format, int i, int *precision)
{
	int prec = -1;

	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			i++;
			*precision = va_arg(args, int);
		}
		else
		{
			prec = 0;

			while (format[i] >= '0' && format[i] <= '9')
			{
				prec = prec * 10 + (format[i] - '0');
				i++;
			}
			*precision = prec;
		}
	}
	return (i);
}
