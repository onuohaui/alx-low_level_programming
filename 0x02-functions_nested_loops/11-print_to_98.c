#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number to start printing from
 * Return: Always 0
 */

void print_to_98(int n)
{
	while (n != 98)
	{
		_putchar(n / 100 + '0');
		_putchar((n / 10) % 10 + '0');
		_putchar(n % 10 + '0');
		_putchar(',');
		_putchar(' ');
		n = (n < 98) ? n + 1 : n - 1;
	}
	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
