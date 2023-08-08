#include <stdlib.h>

/**
 * _strlen - Computes the length of a string.
 * @str: The string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}
	return (count);
}

/**
 * get_word_len - Computes the length of a word in a string.
 * @str: The string.
 * @index: The starting index of the word in the string.
 *
 * Return: The length of the word.
 */
int get_word_len(char *str, int index)
{
	int len = 0;

	while (str[index] && str[index] != ' ')
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * strtow - Splits a string into words.
 * @str: The string.
 *
 * Description: If str == NULL or str == "", return NULL.
 *
 * Return: Pointer to an array of words, or NULL on failure.
 */
char **strtow(char *str)
{
	int i, j, k, num_words, word_len;
	char **words;

	if (!str || _strlen(str) == 0)
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	for (i = 0, k = 0; i < num_words; i++)
	{
		while (str[k] == ' ')
			k++;
		word_len = get_word_len(str, k);
		words[i] = malloc((word_len + 1) * sizeof(char));
		if (!words[i])
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		for (j = 0; j < word_len; j++, k++)
			words[i][j] = str[k];
		words[i][j] = '\0';
	}
	words[num_words] = NULL;

	return (words);
}
