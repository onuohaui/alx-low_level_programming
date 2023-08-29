#include "lists.h"
#include <stdio.h>

size_t find_loop_length(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_loop_length - Determines the length of a looped listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: 0 if no loop, otherwise the number of unique nodes.
 */
size_t find_loop_length(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t node_count = 1;

	if (!head || !head->next)
		return (0);

	slow_ptr = head->next;
	fast_ptr = head->next->next;

	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				node_count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			slow_ptr = slow_ptr->next;
			while (slow_ptr != fast_ptr)
			{
				node_count++;
				slow_ptr = slow_ptr->next;
			}

			return (node_count);
		}

		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next ? fast_ptr->next->next : NULL;
	}

	return (0);
}

/**
 * print_listint_safe - Safely prints a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: The total number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count, i = 0;

	node_count = find_loop_length(head);

	if (node_count == 0)
	{
		for (; head; node_count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (i = 0; i < node_count; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node_count);
}
