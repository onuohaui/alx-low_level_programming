#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to dog struct to initialize
 * @name: Dog name
 * @age: Dog age
 * @owner: Dog owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{

	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
