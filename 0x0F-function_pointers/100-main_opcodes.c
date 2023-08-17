#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Prints the opcodes of a given memory region
 * @start_address: The starting address of the memory region
 * @num_bytes: The number of bytes to print
 */
void print_opcodes(char *start_address, int num_bytes)
{
	int i;
	unsigned char *opcodes = (unsigned char *)start_address;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", opcodes[i]);
	}

	printf("\n");
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 1 if incorrect, 2 if negative
 */
int main(int argc, char *argv[])
{
	int num_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes((char *)&main, num_bytes);

	return (0);
}
