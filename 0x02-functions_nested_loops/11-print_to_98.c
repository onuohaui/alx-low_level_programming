#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number to start printing from
 * Return: always 0
 */

void print_to_98(int n)
{
	int i;

	i = n;

	while (i <= 98)
	{
		if (i >= 100)
		{
			_putchar(i / 100 + '0');
		}
		else
		{
			_putchar(' ');
			_putchar(' ');
		}

		_putchar((i / 10) % 10 + '0');
		_putchar(i % 10 + '0');

		if (i != 98)
		{
			_putchar(',');
			_putchar(' ');
		}

		i++;
	}

	_putchar('\n');
}
