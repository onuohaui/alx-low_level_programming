#include <stdio.h>

/**
 * main - find and print the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long div = 2, maxPrime;

	while (n != 0)
	{
		if (n % div != 0)
			div = div + 1;
		else
		{
			maxPrime = n;
			n = n / div;

			if (n == 1)
			{
				printf("%lu\n", maxPrime);
				break;
			}
		}
	}

	return (0);
}
