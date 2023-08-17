#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Prints numbers followed by newline.
 * @separator: String printed between numbers.
 * @n: Number of integers passed.
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize the argument list */
	va_start(args, n);

	/* Iterate through the arguments and print numbers */
	for (i = 0; i < n; i++)
	{
		int num = va_arg(args, int);

		printf("%d", num);

		/* Print separator if it is not NULL and not the last number */
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	/* Clean up the argument list */
	va_end(args);

	/* Print a new line */
	printf("\n");
}
