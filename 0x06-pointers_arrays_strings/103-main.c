#include "main.h"
#include <stdio.h>

/**
 * perform_calc - check the code
 *
 * @n: Parameter representer the first number
 * @m: Parameter representing the second number
 * @r: Parameter used to stor the resulti
 * @size: Size of buffer
 * Return: Always 0
 */

void perform_calc(char *n, char *m, char *r, int size)
{
	char *res;

	res = infinite_add(n, m, r, size);
	if (res == 0)
	{
		printf("Error\n");
	}
	else
	{
		printf("%s + %s = %s\n", n, m, res);
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char part1[] = "12345678924345743678235745756"
		"7847768578564568587687"
		"6774586734";
	char part2[] = "734563456453743756756784458";
	char part3[] = "90347906634706972346829145"
		"69346259634958693246597324"
		"659762347";
	char part4[] = "956349265983465962349569346";
	char r[100];
	char r2[10];
	char r3[11];

	perform_calc(part1, part3, r, 100);
	perform_calc(part2, part4, r, 100);
	perform_calc("1234567890", "1", r2, 10);
	perform_calc("999999999", "1", r2, 10);
	perform_calc("999999999", "1", r3, 11);

	return (0);
}
