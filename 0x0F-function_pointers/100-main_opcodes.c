#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of a given memory region
 * @argc: number of command-line arguments
 * @argv: array of arguments
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int bytes, i;
	char *func_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	func_ptr = (char *)&main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx", func_ptr[i]);
		if (i < bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
