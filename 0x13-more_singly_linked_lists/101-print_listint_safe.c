#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	tortoise = hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;

		if (tortoise == hare)
		{
			printf("-> [%p] %d\n", (void *)hare, hare->n);
			break;
		}
	}

	return (count);
}
