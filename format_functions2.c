#include "main.h"

/**
 * print_binary - print a number in binary
 * @args: Argument
 *
 * Return: Number of characters
 */
int print_binary(va_list args)
{
	int num, i, count, bit;

	num = va_arg(args, int);
	count = 0;

	for (i = sizeof(int) * 8 - 1; i >= 0; i--)
	{
		bit = (num >> i) & 1;
		putchar(bit + '0');
		count++;
	}

	return (count);
}

/**
 * print_octal - print the octal representation of a number
 * @args: Argument
 *
 * Return: Number of characters
 */
int print_octal(va_list args)
{
	int num, i, count, temp, digits, digit;

	num = va_arg(args, int);
	count = 0;

	if (num == 0)
	{
		putchar('0');
		count++;
	} else
	{
		temp = num;
		digits = 0;

		while (temp != 0)
		{
			temp /= 8;
			digits++;
		}

		for (i = digits - 1; i >= 0; i--)
		{
			digit = (num >> (i * 3)) & 7;
			putchar(digit + '0');
			count++;
		}
	}

		return (count);
}

/**
 * print_c_hex - handles the  Capital case Hexadecimal representation of number
 * @args: Argument
 *
 * Return: number of characters counted
 */
int print_c_hex(va_list args)
{
	int num, i, temp, count, digits, digit;
	char hex_digits[] = "0123456789ABCDEF";

	count = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		putchar('0');
		count++;
	} else
	{
		temp = num;
		digits = 0;

		while (temp != 0)
		{
			temp /= 16;
			digits++;
		}

		for (i = digits - 1; i >= 0; i--)
		{
			digit = (num >> (i * 4)) & 0xF;
			putchar(hex_digits[digit]);
			count++;
		}
	}

	return (count);
}


/**
 * print_l_hex - handles the  Lower case Hexadecimal representation of number
 * @args: Argument
 *
 * Return: number of characters counted
 */
int print_l_hex(va_list args)
{
	int num, i, temp, count, digits, digit;
	char hex_digits[] = "0123456789abcdef";

	count = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		putchar('0');
		count++;
	} else
	{
		temp = num;
		digits = 0;

		while (temp != 0)
		{
			temp /= 16;
			digits++;
		}

		for (i = digits - 1; i >= 0; i--)
		{
			digit = (num >> (i * 4)) & 0xF;
			putchar(hex_digits[digit]);
			count++;
		}
	}

	return (count);
}

/**
 * print_rot13 - handles the rotate by 13 places of a string
 * @args: Argument
 *
 * Return: Number of characters
 */
int print_rot13(va_list args)
{
	char ch;
	char *str;
	int i, count;

	count = 0;
	str = va_arg(args, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (ch >= 'A' && ch <= 'Z')
			ch = ((ch - 'A') + 13) % 26 + 'A';
		else if (ch >= 'a' && ch <= 'z')
			ch = ((ch - 'a') + 13) % 26 + 'a';

		putchar(ch);
		count++;
	}

	return (count);
}
