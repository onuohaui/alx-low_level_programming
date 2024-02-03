#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table you want to add or update the key/value to.
 * @key: The key, cannot be an empty string.
 * @value: The value associated with the key, must be duplicated.
 *         Can be an empty string.
 * 
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Get the index in the hash table array for the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check for collision - if the bucket is not empty */
	temp = ht->array[index];
	while (temp)
	{
		/* Update value if key already exists */
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

	/* Create the new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Insert the node */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
