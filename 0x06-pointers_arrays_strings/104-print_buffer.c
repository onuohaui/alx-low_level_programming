#include <stdio.h>
/**
 * print_buffer - prints a buffer in a specific format
 * @b: the buffer to be printed
 * @size: the size of the buffer
 *
 * Return: nothing
 */

void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", b[i + j] & 0xff);
			else
				printf("  ");
			if (j % 2)
				printf(" ");
		}

		for (j = 0; j < 10; j++)
		{
			if (i + j < size && (b[i + j] > 31 && b[i + j] < 127))
				printf("%c", b[i + j]);
			else if (i + j < size)
				printf(".");
		}

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
