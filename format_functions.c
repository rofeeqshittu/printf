#include "main.h"

/**
 * print_int - handle int format specifier
 * @args: Argument
 *
 * Return: void
 */
int print_int(va_list args)
{
	int num, i, count;
	int isNegative;
	unsigned int absNum;
	char buffer[32];

	i = 0;
	count = 0;

	num = va_arg(args, int);
	absNum = (num < 0) ? -num : num;
	if (absNum == 0)
	{
		buffer[i++] = '0';
	} else
	{
		while (absNum != 0)
		{
			buffer[i++] = '0' + (absNum % 10);
			absNum /= 10;
		}
		if (num < 0)
			buffer[i++] = '-';
	}
	while (i > 0)
	{
		putchar(buffer[--i]);
		count++;
	}
	return (count);
}

/**
 * print_string- handle string format specifier
 * @args: Argument
 *
 * Return: void
 */
int print_string(va_list args)
{
	char *str;
	int count;

	str = va_arg(args, char*);
	count = 0;
	while (*str != '\0')
	{
		putchar(*str);
		str++;
		count++;
	}
}

/**
 * print_char - handle char format specifier
 * @args: Argument
 *
 * Return: void
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	putchar(c);

	return (1);
}

/**
 * print_percent - handle percent format specifier
 * @args: Argument
 *
 * Return: void
 */
int print_percent(va_list args)
{
	putchar('%');

	return (1);
}
