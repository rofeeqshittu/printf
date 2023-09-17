#include "main.h"

/**
 * _printf - My printf function
 * @format: format
 *
 * Return: void
 */
void _printf(const char *format, ...)
{
	int i, found;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			_formatFunction functions[] = {
				{print_int, 'd'},
				{print_string, 's'},
				{print_char, 'c'},
				{print_percent, '%'}
			};

			found = 0;
			for (i = 0; i < sizeof(functions) / sizeof(functions[0]); i++)
			{
				if (*format == functions[i].specifier)
				{
					functions[i].func(args);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				putchar('%');
				putchar(*format);
			}
		} else
			putchar(*format);
		format++;
	}
	va_end(args);
}
