#include <stdlib.h>
#include "binary_trees.h"

/**
 * check_nodes - checks for leaves
 * @node: the tree to be checked
 *
 * Return: returns a value representing height
 */
size_t check_nodes(const binary_tree_t *node)
{
	size_t left;
	size_t right;
	size_t nodes = 1;

	if (node == NULL)
		return (0);
	left = check_nodes(node->left);
	right = check_nodes(node->right);

	nodes += left + right;

	return (nodes);
}
/**
 * check_child - checks how full a node is
 * @node: pointer to the node
 *
 * Return: a value representing the full nodes
 */
size_t check_child(const binary_tree_t *node)
{
	size_t full, left, right;

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	else if (node->left != NULL && node->right != NULL)
	{
		full = 1;
		left = check_child(node->left);
		right = check_child(node->right);
	}
	else
	{
		return (0);
	}
	full += left + right;

	return (full);
}
/**
 * binary_tree_is_full - check if a tree is full or not
 * @tree: pointer to the tree to be checked
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t full;
	size_t full_nodes, total_nodes;

	if (tree == NULL)
		return (0);

	total_nodes = check_nodes(tree);
	full_nodes = check_child(tree);
	full = total_nodes - full_nodes;
	if (full > 0)
		return (0);

	return (1);
}
