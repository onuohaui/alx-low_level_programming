#include <stdio.h>

static const int winning_numbers[] = {9, 8, 10, 24, 75, 9};
static int call_count;
/**
 * rand - Custom implementation of the rand function.
 * This function returns predetermined winning numbers
 * instead of random numbers.
 *
 * Return: Winning numbers one by one, and the bonus number last.
 */
int rand(void)
{
	if (call_count < 5)
	{
		return (winning_numbers[call_count++]);
	}
	else
	{
		return (winning_numbers[5]);
	}
}

/**
 * srand - Custom implementation of the srand function.
 * This function is a placeholder and does not do anything.
 * It's here to match the expected srand signature.
 *
 * @seed: The seed value (unused in this implementation).
 */
void srand(unsigned int seed)
{
}
