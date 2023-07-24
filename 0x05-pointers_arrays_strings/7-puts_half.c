#include "main.h"

/**
 * puts_half - Prints half of a string.
 * @str: The string to print
 */
void puts_half(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	len++;
	for (len /= 2; str[len] != '\0'; len++)
		_putchar(str[len]);

	_putchar('\n');
}
