#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring.
 * @haystack: string to search in
 * @needle: substring to find
 * Return: pointer to the beginning of the located
 * substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*n && *haystack && *n == *haystack)
		{
			haystack++;
			n++;
		}

		if (!*n)
			return (h);

		haystack = h + 1;
	}

	return (NULL);
}
