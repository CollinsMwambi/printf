#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>

typedef int (*print_function_t)(va_list args, char *buffer, int *buffer_index);

typedef struct {
    char specifier;
    int (*print_func)(va_list args, char *buffer, int *buffer_index);
} format_specifier_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int _putchar(char c);

int print_int_recursive(int num);
int print_binary(va_list args);
int print_hex(va_list args);
int print_octal(va_list args);
int print_unsigned(va_list args);
int print_custom_string(va_list args, char *buffer, int *buffer_index);
int print_pointer(va_list args, char *buffer, int *buffer_index);


void handle_rot13(char *str, int len);

int handle_length_modifiers(const char *format, int i, char *length_modifier);
int handle_field_width(const char *format, int i, int *field_width);
int handle_flags(const char *format, int i, int *plus_flag, int *space_flag, int *hash_flag);
int handle_precision(const char *format, int i, int *precision);
int handle_zero_flag(const char *format, int i, int *zero_flag);
int handle_minus_flag(const char *format, int i, int *minus_flag);
int handle_custom_specifiers(va_list args, char *buffer, int *buffer_index, char specifier);

#endif /* MAIN_H */
