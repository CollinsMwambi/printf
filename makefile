CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format
SOURCES = main.c 0-print_char.c 0-print_string.c 0-printf.c 1-print_integers.c 10-handle_precision.c 11-handle_zero_flag.c 12-handle_minus_flag.c 13-handle_custom_specifiers.c 2-print_binary.c 3-print_hex.c 3-print_octal.c 3-print_unsigned.c 5-print_custom_string.c 6-print_pointer.c 7-handle_flags.c 8-handle_length_modifiers.c 9-handle_field_width.c _putchar.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = kilo

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

