#include "main.h"

/**
* print_times_table - Prints the 9 times table starting with 0
*/
void print_times_table(void)
{
int i, j;

for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
int result = i * j;
if (j > 0)
{
_putchar(',');
_putchar(' ');
if (result < 10)
_putchar(' ');
}
if (result < 10)
_putchar(' ');
else
_putchar((result / 10) + '0');
_putchar((result % 10) + '0');
}
_putchar('\n');
}
}
