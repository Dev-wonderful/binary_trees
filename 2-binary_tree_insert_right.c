#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node as the right child of parent
 * @parent: pointer to the parent to be updated
 * @value: data for new node
 *
 * Return: pointer to new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
		binary_tree_t *new_node;

		if (parent == NULL)
			return (NULL);
		new_node = binary_tree_node(parent, value);

		if (parent->right == NULL)
		{
			parent->right = new_node;
			return (new_node);
		}
		new_node->right = parent->right;
		parent->right->parent = new_node;
		parent->right = new_node;

		return (new_node);
}
