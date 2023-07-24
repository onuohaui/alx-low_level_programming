#include "main.h"

/**
 * _strcpy - Copies a string from src to dest
 * @dest: Destination for copying
 * @src: Source string to copy from
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
