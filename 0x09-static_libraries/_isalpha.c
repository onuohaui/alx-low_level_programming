#include "main.h"

/**
 * _isalpha - Checks for alphabetic character
 * @c: The character to check
 * Return: 1 if c is a letter, 0 otherwise
 */

int _isalpha(int c)
{
	return ((_islower(c)) || (_isupper(c)));
}
