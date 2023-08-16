#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array
 * using a comparison function.
 * @array: The array to search.
 * @size: The number of elements in the array.
 * @cmp: The comparison function.
 *
 * Return: The index of the first element for which
 *         the comparison function does not return 0,
 *         or -1 if no match is found or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (index = 0; index < size; index++)
		if (cmp(array[index]) != 0)
			return (index);

	return (-1);
}
