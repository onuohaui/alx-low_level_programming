#include "main.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (0);
}
