#include "main.h"
#include <limits.h>

int main22(void)
{
	_printf("Hello, %s! The answer is %d. The char is %c. the percent is %%. \n", "John", 42, 'A');

	_printf("%d\n", -1024);
	_printf("%d\n", INT_MAX);
	_printf("%d\n", INT_MIN);

	return (0);
}
