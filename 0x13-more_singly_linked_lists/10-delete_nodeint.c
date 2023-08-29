#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the
 *	node at a given index in the list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev = NULL;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		if (temp == NULL)
			return (-1);
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return (-1);

	prev->next = temp->next;
	free(temp);
	return (1);
}
