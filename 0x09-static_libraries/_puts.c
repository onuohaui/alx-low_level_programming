#include "main.h"

/**
 * _puts - prints a string to stdout
 * @s: the string to be printed
 *
 * Return: void
 */
void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}
