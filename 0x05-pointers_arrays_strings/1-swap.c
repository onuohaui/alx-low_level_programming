#include "main.h"

/**
 * swap_int - Swaps the values of two integers
 * @a: The first integer pointer
 * @b: The second integer pointer
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
