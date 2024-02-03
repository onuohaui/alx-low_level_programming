#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table.
 * @ht: The hash table to look into.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element,
 *	or NULL if the key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Compute the index by hashing the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at this index */
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}
