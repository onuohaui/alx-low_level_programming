#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer that the function will use to store the result
 * @size_r: buffer size
 * Return: pointer to the result, or 0 if it cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n, carry = 0;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;

	l = (i > j) ? i : j;

	if (size_r <= l + 1)
		return (0);

	r[l + 1] = '\0';

	for (k = 0; k <= l; k++)
	{
		m = (i > 0) ? n1[--i] - '0' : 0;
		n = (j > 0) ? n2[--j] - '0' : 0;

		r[l - k] = (m + n + carry) % 10 + '0';
		carry = (m + n + carry) / 10;
	}

	return ((r[0] == '0') ? r + 1 : r);
}
