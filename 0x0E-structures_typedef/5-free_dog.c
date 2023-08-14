#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees a dog_t struct
 * @d: Pointer to dog_t struct to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);

	free(d->owner);

	free(d);
}
