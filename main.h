#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(const char *str);

/**
 * struct conv - Conversion structure
 *
 * @convers_handler: The conversion specifier
 * @specifier: The specifier
 * @handler: The function associated
 */
typedef struct convers_handler
{
	const char *specifier;
	void (*handler)(va_list args, int *count);
} conversion_handler;

/* conversion specifier functions */
void handle_char(va_list args, int *count);
void handle_str(va_list args, int *count);
void handle_percent(va_list args, int *count);

void (*get_convers_func(const char *s))(va_list args, int *count);

#endif /* MAIN_H */
