#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_loop - Checks for loop in linked list
 * @address_lookup: Array of visited node addresses
 * @count: Number of visited nodes
 * @next_node: Next node to visit
 * Return: 1 if loop found, 0 otherwise
 */
int find_loop(void **address_lookup, size_t
		count, const listint_t *next_node)
{
	size_t i;

	for (i = 0; i < count; i++)
	{
		if (address_lookup[i] == next_node)
		{
			printf("-> [%p] %d\n", (void *)next_node,
					next_node->n);
			return (1);
		}
	}
	return (0);
}


/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;
	void **address_lookup = NULL;

	if (head == NULL)
		exit(98);

	while (current)
	{
		address_lookup = realloc(address_lookup,
				sizeof(void *) * (count + 1));
		if (!address_lookup)
			exit(98);

		printf("[%p] %d\n", (void *)current, current->n);
		address_lookup[count++] = (void *)current;

		if (find_loop(address_lookup, count, current->next))
			break;

		current = current->next;
	}

	free(address_lookup);
	return (count);
}
