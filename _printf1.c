#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Counter for the number of characters printed

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            // Handle the conversion specifier
            switch (*format)
            {
                case 'c':
                {
                    char ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    fputs(str, stdout);
                    count += strlen(str);
                    break;
                }
                case '%':
                {
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
    return count;
}

