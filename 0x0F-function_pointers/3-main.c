#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Performs simple operations.
 * @argc: Number of arguments.
 * @argv: Arguments passed.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*opfunc)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	opfunc = get_op_func(argv[2]);
	if (opfunc == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", opfunc(a, b));

	return (0);
}
