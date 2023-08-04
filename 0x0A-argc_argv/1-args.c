#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: Array of character pointers listing all the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int num_arguments;

	(void)argv;

	num_arguments = argc - 1;
	printf("%d\n", num_arguments);

	return (0);
}
