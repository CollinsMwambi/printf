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

	int buffer_index = 0, field_width = 0, precision = -1, zero_flag = 0;

	int i = 0, count = 0, plus_flag = 0, space_flag = 0, hash_flag = 0;

	int minus_flag = 0;

	char length_modifier = '\0';

	char buffer[1024];

	format_specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex},
		{'S', print_custom_string},
		{'p', print_pointer},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (buffer_index == 1024)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}

		i = handle_flags(format, i, &plus_flag, &space_flag, &hash_flag);
		i = handle_length_modifiers(format, i, &length_modifier);
		i = handle_field_width(format, i, &field_width);
		i = handle_precision(format, i, &precision);
		i = handle_zero_flag(format, i, &zero_flag);
		i = handle_minus_flag(format, i, &minus_flag);

		if (format[i] == '%' && format[i + 1] == 'p')
		{
			i++;
			count += print_pointer(args, buffer, &buffer_index);
		}
		else if (format[i] == '%' && format[i + 1] == 'S')
		{
			i++;
			count += print_custom_string(args, buffer, &buffer_index);
		}
		else if (format[i] == '%' && (format[i + 1] == 'r' || format[i + 1] == 'R'))
		{
			char specifier = format[i + 1];

			i++;
			i++;
			count += handle_custom_specifiers(args, buffer, &buffer_index, specifier);
		}
		else
		{
			buffer[buffer_index++] = format[i];
			count++;
		}
		i++;
	}

	if (buffer_index > 0)
		write(1, buffer, buffer_index);

	va_end(args);

	return (count);
}

