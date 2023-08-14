#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic details
 * @name: First name
 * @age: age
 * @owner: Owner's name
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
