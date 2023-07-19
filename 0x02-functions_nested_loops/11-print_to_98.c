#include "main.h"
/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number to start printing from
 * Reture: always 0
 */

void print_to_98(int n)

{
	while (n <= 98)
	{
		if (n >= 100)
		{
			_putchar(n / 100 + '0');
		}
		else
		{
			_putchar(' ');
			_putchar(' ');
		}

		_putchar((n / 10) % 10 + '0');
		_putchar(n % 10 + '0');

		_putchar(',');
		_putchar(' ');
		n++;
	}

	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
