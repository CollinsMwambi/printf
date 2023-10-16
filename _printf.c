#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	int i = 0;

	format_specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] != '\0')
			{
				int j = 0, found = 0;

				while (specifiers[j].specifier)
				{
					if (format[i] == specifiers[j].specifier)
					{
						count += specifiers[j].printer(args);
						found = 1;
					}
					j++;
				}
				if (found == 0)
				{
					_putchar('%');
					_putchar(format[i]);
					count += 2;
				}
			}
		}
		i++;
	}
	va_end(args);

	return (count);
}

