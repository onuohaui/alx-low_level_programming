#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0
*/

int main(void)
{
int i = 0;
int j;
int k;

while (i <= 7)
{
j = i + 1;

while (j <= 8)
{
k = j + 1;

while (k <= 9)
{
putchar(i + '0');
putchar(j + '0');
putchar(k + '0');

if (i != 7 || j != 8 || k != 9)
{
putchar(',');
putchar(' ');
}

k++;
}

j++;
}

i++;
}

putchar('\n');

return (0);
}
