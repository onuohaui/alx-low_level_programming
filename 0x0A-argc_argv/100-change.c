#include <stdio.h>
#include <stdlib.h>

#define COINS 5

/**
 * get_coin_value - gets the value of a coin at a given index
 * @index: the index of the coin
 *
 * Return: the value of the coin
 */
int get_coin_value(int index)
{
	int values[COINS] = {25, 10, 5, 2, 1};

	return (values[index]);
}

/**
 * main - Calculate minimum coins for change
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0, i;

	/* Check for the correct number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert the argument to an integer */
	cents = atoi(argv[1]);

	/* Check if the argument is negative */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Calculate the minimum number of coins needed */
	for (i = 0; i < COINS; i++)
	{
		while (cents >= get_coin_value(i))
		{
			coins++;
			cents -= get_coin_value(i);
		}
	}

	/* Print the result */
	printf("%d\n", coins);

	return (0);
}
