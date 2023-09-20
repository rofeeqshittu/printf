#include "main.h"

/**
 * _printf - My printf function
 * @format: format
 *
 * Return: void
 */
int _printf(const char *format, ...)
{
	int i, found, count;
	int numFunction;
	va_list args;
	_formatFunction functions[] = {
		{print_int, 'd'}, {print_int, 'i'},
		{print_string, 's'},
		{print_char, 'c'},
		{print_percent, '%'}
	};

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			found = 0;
			numFunction = sizeof(functions) / sizeof(functions[0]);
			for (i = 0; i < numFunction; i++)
			{
				if (*format == functions[i].specifier)
				{
					count += functions[i].func(args);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		} else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}
