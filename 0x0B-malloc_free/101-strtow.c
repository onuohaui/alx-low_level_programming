#include <stdlib.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Description: Splits str into individual words, where words
 * are separated by spaces. Returns a pointer to an array of
 * strings (words). Each element of the array contains one word.
 * The last element of the returned array is NULL.
 * Returns NULL if str is NULL or empty.
 * If malloc fails, function returns NULL.
 * The caller is responsible for freeing the allocated memory.
 *
 * Return: Pointer to array of words, or NULL on failure
 */

char **strtow(char *str)
{
	char **words;
	int i, j, k = 0, len = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			len++;
	}

	if (len == 0)
		return (NULL);

	len++;

	words = (char **)malloc(sizeof(char *) * len);
	if (words == NULL)
		return (NULL);

	k = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			continue;

		words[k] = (char *)malloc(sizeof(char) * (j - i + 2));
		if (words[k] == NULL)
			return (NULL);

		j = 0;
		while (str[i] != ' ' && str[i] != '\0')
		{
			words[k][j++] = str[i++];
		}
		words[k++][j] = '\0';
	}
	words[k] = NULL;
	return (words);
}
