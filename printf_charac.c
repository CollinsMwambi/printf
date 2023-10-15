#include "main.h"

/**
 * printf_charac - prints a binary number
 * @args: the arguements to use
 * @printed: the printed characters
 * Return: printed charcaters
 */

int printf_charac(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}
