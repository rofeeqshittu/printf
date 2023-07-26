#include "main.h"
#include <stddef.h>

/**
 * get_convers_func - Function that selects the correct function
 *	to format specifier used by user.
 * @s: The conversion specifier used by user.
 *
 * Return: pointer to the conversion function
 */
void (*get_convers_func(const char *s))(va_list args, int *count)
{
	int i;
	static const conversion_handler convs[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"%", handle_percent},
		{NULL, NULL}
	};

	i = 0;
	while (convs[i].specifier != NULL)
	{
		if (strcmp(s, convs[i].specifier) == 0)
			return (convs[i].handler);
		i++;
	}

	return (NULL);
}
