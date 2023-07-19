#include "main.h"

/**
 * print_to_98 - Print all natural numbers from n to 98
 * @n: The number to start printing from
 * Return: always 0
 */


void print_to_98(int n)
{
	while (n <= 98)
	{
		_putchar(n / 10 + '0');
		_putchar(n % 10 + '0');

		if (n != 98)
		{
			_putchar(',');
			_putchar(' ');
		}

		n++;
	}

	_putchar('\n');
}
