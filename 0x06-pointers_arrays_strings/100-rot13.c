#include "main.h"

/**
 * rot13 - Encode a string using rot13
 * @s: The string to encode
 *
 * Return: A pointer to the encoded string
 */
char *rot13(char *s)
{
	int i = 0;
	int j;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (s[i])
	{
		for (j = 0; input[j]; j++)
		{
			if (s[i] == input[j])
			{
				s[i] = output[j];
				break;
			}
		}
		i++;
	}

	return (s);
}
