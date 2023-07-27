#include "main.h"
#include <stdio.h>
#include <string.h>  /* add this line */

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char str1[] = "Expect the best. Prepare for the worst.";
	char str2[] = " Capitalize on what comes.\nhello world!";
	char str3[] = " hello-world 0123456hello world\thello world.";
	char str4[] = "hello world\n";
	char str[200];  /* make sure the size is large enough */
	char *ptr;

	strcpy(str, str1);
	strcat(str, str2);
	strcat(str, str3);
	strcat(str, str4);

	ptr = cap_string(str);
	printf("%s", ptr);
	printf("%s", str);
	return (0);
}
