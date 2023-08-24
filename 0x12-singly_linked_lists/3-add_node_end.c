#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - calculates the length of a string.
 * @str: string whose length to calculate.
 *
 * Return: length of the string.
 */
static unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be included in the new node.
 *
 * Return: Address of the new node or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp;

	/* allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* assign the length using helper function */
	new_node->len = _strlen(str);

	/* new node's next will be NULL since it's the last node */
	new_node->next = NULL;

	/* if the list is empty, assign new node to head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* traverse the list to the last node */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* add the new node to the end of the list */
	temp->next = new_node;

	return (new_node);
}
