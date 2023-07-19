#include "main.h"
/**
* add - Adds two integers
* @a: The first integer
* @b: The second integer
*
* Return: The sum of the two integers
*/

int add(int a, int b)
{
	int sum = a + b;

	_putchar(sum / 10 + '0');
	_putchar(sum % 10 + '0');

	return (sum);
}
