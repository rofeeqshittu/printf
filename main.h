#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct _fF - Structure func
 * @func: function pointer
 * @specifier: specifier
 */
typedef struct _fF
{
	void (*func)(va_list);
	char specifier;
} _formatFunction;

void print_int(va_list args);
void print_string(va_list args);
void print_char(va_list args);
void print_percent(va_list args);

void _printf(const char *format, ...);
#endif /* MAIN_H */
