#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords for 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char password[84];
	int index;

	srand(time(0));

	for (index = 0; index < 84; index++)
	{
		password[index] = 33 + (rand() % 94);
	}

	password[index] = '\0';

	printf("%s", password);

	return (0);
}
