#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: A pointer to the binary string.
 * Return: The converted unsigned int, or 0 if there's an error.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = result * 2 + (*b - '0');
	}

	return (result);
}

