#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the null byte,
 *           to the buffer pointed to by dest
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: a pointer to the resulting string @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
