#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c);

/**
 * print_number - Prints an array of integers as a number
 * @arr: The array of integers to print
 * @size: The size of the array
 */
void print_number(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		_putchar(arr[i] + '0');
	}
}

/**
 * multiply - Multiplies two arrays of integers
 * @num1: The first array of integers
 * @size1: The size of the first array
 * @num2: The second array of integers
 * @size2: The size of the second array
 *
 * Return: A pointer to the resulting array
 */
int *multiply(int *num1, int size1, int *num2, int size2)
{
	int i, j;
	int *result;

	result = calloc(size1 + size2, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = size1 - 1; i >= 0; i--)
	{
		for (j = size2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += num1[i] * num2[j];
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}

	return (result);
}

/**
 * convert_to_array - Converts a string to an array of integers
 * @str: The string to convert
 * @size: A pointer to store the size of the array
 *
 * Return: A pointer to the resulting array
 */
int *convert_to_array(char *str, int *size)
{
	int i;
	int *num;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}

	*size = i;
	num = malloc(sizeof(int) * (*size));

	if (num == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < *size; i++)
	{
		num[i] = str[i] - '0';
	}

	return (num);
}

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments
 * @argv: An array of strings containing the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int size1, size2;
	int *num1, *num2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = convert_to_array(argv[1], &size1);
	num2 = convert_to_array(argv[2], &size2);

	result = multiply(num1, size1, num2, size2);
	print_number(result, size1 + size2);
	printf("\n");

	free(num1);
	free(num2);
	free(result);

	return (0);
}
