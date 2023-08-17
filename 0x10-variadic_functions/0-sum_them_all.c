#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of parameters passed to the function.
 *
 * Return: The sum of all parameters.
*/

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;

	/* If n is 0, return 0 */
	if (n == 0)
		return (0);

	/* Initialize the argument list */
	va_start(args, n);

	/* Iterate through the arguments and calculate the sum */
	for (i = 0; i < n; i++)
	{
		int arg = va_arg(args, int);

		sum += arg;
	}

	/* Clean up the argument list */
	va_end(args);

	return (sum);
}
