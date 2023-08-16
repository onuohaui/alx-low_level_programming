#include "function_pointers.h"

/**
 * print_name - Prints a name using a function given as a parameter.
 * @name: The name to print.
 * @f: The function to use to print the name.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
