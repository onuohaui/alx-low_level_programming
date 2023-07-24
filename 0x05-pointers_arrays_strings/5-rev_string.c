#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: The string to be reversed
 */
void rev_string(char *s)
{
	char temp;
	int i, len;

	len = 0;
	while (s[len] != '\0')
		len++;

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
