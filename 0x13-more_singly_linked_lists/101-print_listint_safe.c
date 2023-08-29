#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t list
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head, *fast = head;

	if (head == NULL)
	{
		exit(98);
	}

	while (fast != NULL && fast->next != NULL)
	{
		/* Print current node */
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		/* Move one step for slow */
		slow = slow->next;

		/* Move two steps for fast */
		fast = fast->next->next;

		/* If loop is detected */
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			return (count);
		}
	}

	/* Print remaining nodes if no loop */
	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	return (count);
}
