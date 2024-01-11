#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the
 * data (n) of a dlistint_t linked list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: sum of all the data (n), or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Traverse the list and accumulate the sum of the data (n) */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
