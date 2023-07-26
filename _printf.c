#include "main.h"

/**
 * _printf - a function that produce an output according to a format
 * @format: Parameter passed
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	void (*handler)(va_list, int *);
	va_list args;
	
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handler = get_convers_func(format);
			if (handler != NULL)
			{
				handler(args, &count);
				format++;
			}
			else
			{
				putchar('%');
				count++;
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
