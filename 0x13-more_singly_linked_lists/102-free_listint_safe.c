#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;

		/* Set the next pointer to NULL to avoid accessing freed memory */
		temp->next = NULL;
		free(temp);

		if (temp <= current)
			break;
	}

	*h = NULL;

	return (count);
}
