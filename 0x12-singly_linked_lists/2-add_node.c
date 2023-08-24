#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be included in the new node.
 *
 * Return: Address of the new node or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len = 0;

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

	/* compute the length of the string */
	while (str[len])
		len++;

	/* assign the length */
	new_node->len = len;

	/* link the new node to the head of the list */
	new_node->next = *head;

	/* change the head pointer to the new node */
	*head = new_node;

	return (new_node);
}
