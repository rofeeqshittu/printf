#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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
int print_binary(va_list args);
int print_octal(va_list args);
/* int print_unsigned_int(va_list args); */
/* int print_pointer(va_list args); */
int print_c_hex(va_list args);
int print_l_hex(va_list args);
int print_reversed(va_list args);
int print_rot13(va_list args);

#endif /* MAIN_H */
