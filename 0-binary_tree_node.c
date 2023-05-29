#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - inserts a child node to the parent node from the left
 * @parent: parent node to be updated
 * @value: the data to be inserted in the new node
 *
 * Return: returns the newly created node address or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
		binary_tree_t *new_node;

		new_node = malloc(sizeof(binary_tree_t));
		new_node->parent = parent;
		new_node->n = value;

		return (new_node);
}
