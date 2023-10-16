#include "main.h"

/**
 * _print_char - Helper function to print a character
 * @args: A `va_list` containing the character to print
 *
 * This function takes a `va_list` containing the character to print
 * and prints it to the standard output.
 *
 * Return: Number of characters printed (always 1)
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * _print_string - Helper function to print a string or "(null)"
 *@args: A `va_list` containing the string to print
 *
 *This function takes a `va_list` containing the string to print
 *and prints it to the standard output.
 *
 * Return: Number of characters printed
 */

int _print_string(va_list args)
{
	int printed = 0;

	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		printed++;
		str++;
	}

	return (printed);
}

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * @...: Variable number of arguments
 * Return: Number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
					printed += _print_char(args);
					break;
				case 's':
					printed += _print_string(args);
					break;
				case 'd':
				case 'i':
					printed += printf_integer(args, printed);
					break;
				case '%':
					_putchar('%');
					printed++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (printed);
}
