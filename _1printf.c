#include "main.h"
#include <stdarg.h>

/**
 * _printf - a function that produces output according to a format
 *
 * Return: the no of characters printed
 */
int _printf(const char *format, ...)
{
	char ch;
	char *str;
	int count;
	va_list args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c': {
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				} case 's': {
					char *str = va_arg(args, char *);
					fputs(str, stdout);
					count += strlen(str);
					break;
				} case '%': {
					putchar('%');
					count++;
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
