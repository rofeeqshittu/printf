#include "main.h"

/**
 * handle_char - character specifier function
 * @args: Argument
 * @count: Count
 *
 * Return: void
 */
void handle_char(va_list args, int *count)
{
	char ch;

	ch = va_arg(args, int);
	putchar(ch);
	(*count)++;
}

/**
 * handle_str - string format specifier function
 * @args: Argument
 * @count: Count
 *
 * Return: void
 */
void handle_str(va_list args, int *count)
{
	char *str;

	str = va_arg(args, char*);
	write(1, str, strlen(str));
	(*count) += strlen(str);
}

/**
 * handle_percent - percent (%) format specifier
 * @args: Argument
 * @count: Count
 *
 * Return: void
 */
void handle_percent(va_list args, int *count)
{
	(void)args;

	putchar('%');
	(*count)++;
}
