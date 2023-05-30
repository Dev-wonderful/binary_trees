#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - getting the depth of a node
 * @tree: The pointer to the tree or node
 *
 * Return: the depth or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 1;

	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	
	depth += binary_tree_depth(tree->parent);

	return (depth);
}
