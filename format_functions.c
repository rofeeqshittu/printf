#include "main.h"

/**
 * print_int - handle int format specifier
 * @args: Argument
 *
 * Return: void
 */
void print_int(va_list args)
{
	int num, i;
	int isNegative;
	char buffer[32];

	i = 0;

	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[i++] = '0';
	} else
	{
		isNegative = (num < 0);
		if (isNegative)
			num = -num;

		while (num != 0)
		{
			buffer[i++] = '0' + (num % 10);
			num /= 10;
		}

		if (isNegative)
			buffer[i++] = '-';
	}
	while (i > 0)
		putchar(buffer[--i]);
}

/**
 * print_string- handle string format specifier
 * @args: Argument
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char*);
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

/**
 * print_char - handle char format specifier
 * @args: Argument
 *
 * Return: void
 */
void print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	putchar(c);
}

/**
 * print_percent - handle percent format specifier
 * @args: Argument
 *
 * Return: void
 */
void print_percent(va_list args)
{
	putchar('%');
}
