#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2D array of integers
 * @width: Width of the 2D array
 * @height: Height of the 2D array
 *
 * Description: Allocates a 2D array of integers with width and height
 * specified by parameters. Initializes each element to 0.
 * On success, returns a pointer to the 2D array.
 * Returns NULL on failure, if width or height is 0 or negative,
 * or if malloc fails. If malloc fails, frees any previously
 * allocated memory.
 *
 * Return: Pointer to 2D array, or NULL on failure
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}

	return (grid);
}
