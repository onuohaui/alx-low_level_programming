#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point of the program for Task 1.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 *
 * Return: Always returns 0 (success).
 */
int main(int ac, char **av)
{
	int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s filename text\n", av[0]);
		exit(1);
	}

	res = create_file(av[1], av[2]);

	printf("-> %i)\n", res);

	return (0);
}
