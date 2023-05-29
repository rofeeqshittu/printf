#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * struct conv - Conversion structure
 *
 * @conv: The conversion specifier
 * @f: The function associated
 */
typedef struct conv
{
	char *conv;
	void (*f)(va_list);
} conv_t;

/* get_convers_func prototype */
void (*get_convers_func(char *s));

/* conversion specifier functions */
void print_char(char *abc);
void print_str(char *str);
void p_percent(char *num);

#endif /* MAIN_H */
