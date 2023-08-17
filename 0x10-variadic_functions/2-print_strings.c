#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Prints strings followed by newline.
 * @separator: String printed between strings.
 * @n: Number of strings passed.
 *
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize the argument list */
	va_start(args, n);

	/* Iterate through the arguments and print strings */
	for (i = 0; i < n; i++)
	{
		char *str = va_arg(args, char *);

		/* Print (nil) if the string is NULL */
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		/* Print separator if it is not NULL and not the last string */
		if (separator != NULL && i < n - 1)

			printf("%s", separator);
	}

	/* Clean up the argument list */
	va_end(args);

	/* Print a new line */
	printf("\n");
}
