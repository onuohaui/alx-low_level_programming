#include "main.h"

/**
 * print_number - Print an integer
 * @n: The integer to print
 */
void print_number(int n)
{
	unsigned int m, digit, flag = 0;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}
	else
	{
		m = n;
	}

	if (m / 10)
	{
		print_number(m / 10);
	}

	digit = m % 10;

	if (flag == 0)
	{
		_putchar('0' + digit);
		flag = 1;
	}
}
