#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as the left child of parent
 * @parent: pointer to the parent to be updated
 * @value: data for new node
 *
 * Return: pointer to new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
		binary_tree_t *new_node;

		if (parent == NULL)
			return (NULL);
		new_node = malloc(sizeof(binary_tree_t));
		new_node->parent = parent;
		new_node->n = value;

		if (parent->left == NULL)
		{
			parent->left = new_node;
			return (new_node);
		}
		new_node->left = parent->left;
		parent->left->parent = new_node;
		parent->left = new_node;

		return (new_node);

}
