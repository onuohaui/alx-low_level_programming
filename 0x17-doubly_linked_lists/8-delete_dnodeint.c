#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a specified index
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted, starting from 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* If deleting the first node */
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the node to be deleted */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	/* If the node to delete is found */
	if (current != NULL)
	{
		if (current->next != NULL)
			current->next->prev = current->prev;
		if (current->prev != NULL)
			current->prev->next = current->next;

		free(current);
		return (1);
	}

	return (-1);
}
