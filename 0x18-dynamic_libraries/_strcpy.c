#include "main.h"

/**
 * _strcpy - copies the string pointed
 * to by src, including the terminating null byte,
 * to the buffer pointed to by dest.
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
