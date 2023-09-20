#include "main.h"

/**
 * print_char - handle char format specifier
 * @args: Argument
 *
 * Return: 1
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	putchar(c);

	return (1);
}

/**
 * print_string- handle string format specifier
 * @args: Argument
 *
 * Return: Num of characters
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

	return (count);
}

/**
 * print_reversed - prints the reversed string of a string given
 * @args: Argument
 *
 * Return: characters count
 */
int print_reversed(va_list args)
{
	char *str;
	int i, count, length;

	count = 0;
	str = va_arg(args, char *);
	length = strlen(str);

	for (i = length - 1; i >= 0; i--)
	{
		putchar(str[i]);
		count++;
	}

	return (count);
}

/**
 * print_percent - handle percent format specifier
 * @args: Argument
 *
 * Return: 1
 */
int print_percent(va_list args __attribute__((unused)))
{
	putchar('%');

	return (1);
}

/**
 * print_int - handle int format specifier
 * @args: Argument
 *
 * Return: void
 */
int print_int(va_list args)
{
	int num, i, count;
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

