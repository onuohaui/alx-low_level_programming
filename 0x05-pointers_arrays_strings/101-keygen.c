#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char password[84];
	int index;

	// Add 2 upper case, 2 lowercase, 2 digits
	password[0] = 'A' + (rand() % 26); 
	password[1] = 'a' + (rand() % 26);

	password[2] = '0' + (rand() % 10);
	password[3] = '0' + (rand() % 10);

	// Fill remaining with random ascii 33-126
	for (index = 4; index < 84; index++) {
		password[index] = 33 + (rand() % 94); 
	}

	password[index] = '\0';

	printf("%s", password);

	return (0);
}
