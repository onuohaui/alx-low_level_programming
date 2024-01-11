#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the doubly linked list
 * @index: index of the node, starting from 0
 *
 * Return: the nth node of a dlistint_t
 * linked list, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	/* Traverse the list until the specified index is reached */
	while (head != NULL)
	{
		if (count == index)
			return (head);
		head = head->next;
		count++;
	}

	/* If the node does not exist, return NULL */
	return (NULL);
}
