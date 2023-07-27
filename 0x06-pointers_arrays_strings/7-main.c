#include "main.h"
#include <stdio.h>

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[] = "Expect the best. Prepare for the worst.";
	char s2[] = " Capitalize on what comes.\n";
	char *p;

	p = leet(s1);
	printf("%s", p);
	printf("%s", s1);
	p = leet(s2);
	printf("%s", p);
	printf("%s", s2);
	return (0);
}
