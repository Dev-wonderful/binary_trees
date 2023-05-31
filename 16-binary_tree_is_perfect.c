#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

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
 * check_height - looks for longest path
 * @node: the tree to be checked
 *
 * Return: returns a value representing height
 */
size_t check_height(const binary_tree_t *node)
{
	size_t height = 1;
	size_t left, right;

	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (0);
	left = check_height(node->left);
	right = check_height(node->right);
	if (left >= right)
		height += left;
	else
		height += right;

	return (height);
}
/**
 * power - exponent of a number
 * @base: base number
 * @exponent: the exponent of the base
 *
 * Return: the exponentiation value
 */
size_t power(int base, size_t exponent)
{
	size_t temp;

	if (exponent == 0)
		return (1);

	temp = power(base, exponent / 2);
	if ((exponent % 2) == 0)
		return (temp * temp);
	else
		return (base * temp * temp);
}
/**
 * binary_tree_is_perfect - checks if a tree is on the same level & max nodes
 * @tree: pointer to the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t perfect;
	size_t height, total_nodes, max_nodes;

	if (tree == NULL)
		return (0);

	height = check_height(tree);
	total_nodes = check_nodes(tree);
	max_nodes = power(2, (height + 1));
	perfect = (max_nodes - 1) - total_nodes;
	if (perfect > 0)
		return (0);

	return (1);
}
