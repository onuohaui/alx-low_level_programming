#include <stdio.h>

/**
 * main - prints the number of arguments passed to it
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	printf("Program name: %s\n", argv[0]);
	return (0);
}
