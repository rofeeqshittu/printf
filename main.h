#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
/**
 * struct _fF - Structure func
 * @func: function pointer
 * @specifier: specifier
 */
typedef struct _fF
{
	int (*func)(va_list);
	char specifier;
} _formatFunction;

int print_int(va_list args);
int print_string(va_list args);
int print_char(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
