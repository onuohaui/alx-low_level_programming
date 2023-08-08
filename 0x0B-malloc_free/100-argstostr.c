#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of a program
 * @ac: The number of arguments passed to the program
 * @av: An array of pointers to the arguments
 *
 * Description: Concatenates all arguments in av into a new string.
 * Adds a newline after each argument. Returns a pointer
 * to the new string. Returns NULL if ac == 0 or av == NULL,
 * or on failure. The caller is responsible for freeing the
 * allocated memory for the returned string.
 *
 * Return: Pointer to new string, or NULL on failure
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	len++;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[len] = av[i][j];
			len++;
		}
		str[len] = '\n';
		len++;
	}

	str[len] = '\0';

	return (str);
}
