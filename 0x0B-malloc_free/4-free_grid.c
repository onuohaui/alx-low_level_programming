#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid previously allocated by alloc_grid
 * @grid: Pointer to the 2D array of integers
 * @height: Height of the 2D array
 *
 * Description: Frees the memory allocated for a 2D grid. Loops
 * through each row and frees it, then frees the array of pointers.
 * Should only be used on grids allocated by alloc_grid.
 *
 * Return: None
 */

#include <stdlib.h>

void free_grid(int **grid, int height)
{

	int i;

	for (i = 0; i < height; i++)

	{
		free(grid[i]);
	}

	free(grid);
}
