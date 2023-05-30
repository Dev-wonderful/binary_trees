#include <stdlib.h>
#include "binary_trees.h"

/**
 * check - counts all nodes
 * @node: the tree to be checked
 *
 * Return: returns a value representing height
 */
size_t check(const binary_tree_t *node)
{
	size_t size = 1;
	size_t left, right;

	if (node->left != NULL)
		left = check(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = check(node->right);
	else
		right = 0;
	size += left + right;

	return (size);
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to be measured
 *
 * Return: height of tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = check(tree);

	return (size);
}
