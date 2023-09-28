#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 * Description: This function prints the binary representation of a given
 *              unsigned long integer using recursion. It uses the custom
 *              _putchar function to output each binary digit.
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	putchar((n & 1) + '0');
}
