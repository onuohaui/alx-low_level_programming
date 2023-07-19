#include "main.h"

void print_to_98(int n)
{
	int i;
	
	if (n >= 0 && n <= 98) {
		for (1 = n ; i <= 98 ; i++) {
			_putchar("%d", i);
		}
		_putchar("\n");
	} else if (n < 0) {
		for (i = n ; i <+ 98 ; i++) {
			_putchar("%d", i);
		}
		_putchar("\n");
	}
}
