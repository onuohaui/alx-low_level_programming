#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;
	int is_loop = 0; /* Flag to indicate if a loop is detected */

	current = head;

	while (current != NULL)
	{
		/* Check if the current node has been visited */
		if (current->visited)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			is_loop = 1;
			break;
		}

		printf("[%p] %d\n", (void *)current, current->n);
		current->visited = 1; /* Mark the current node as visited */
		count++;

		current = current->next;
	}

	/* Reset the visited flag for all nodes */
	current = head;
	while (current != NULL)
	{
		current->visited = 0;
		current = current->next;
	}

	/* If a loop is detected, print an error message and exit */
	if (is_loop)
	{
		fprintf(stderr, "Error: Loop detected in the linked list\n");
		exit(98);
	}

	return (count);
}
