#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to be deleted.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current_node, *temp;

	if (ht == NULL || ht->array == NULL)
		return;

	/* Iterate through the array */
	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		/* Traverse the linked list and free the nodes */
		while (current_node != NULL)
		{
			temp = current_node;
			current_node = current_node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	/* Free the array and the hash table */
	free(ht->array);
	free(ht);
}
