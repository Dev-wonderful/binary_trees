#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - to check if a node is a leaf
 * @node: the node to be checked
 *
 * Return: 1 if true or 0 if false
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
/**
 * check - checks for leaves
 * @node: the tree to be checked
 *
 * Return: returns a value representing height
 */
size_t check(const binary_tree_t *node)
{
	size_t leaf;
	size_t left, right;

	leaf = binary_tree_is_leaf(node);
	if (leaf == 1)
		return (leaf);

	if (node->left != NULL)
		left = check(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = check(node->right);
	else
		right = 0;
	leaf = left + right;

	return (leaf);
}
/**
 * binary_tree_leaves - count the number of leaves of a binary tree
 * @tree: pointer to the root node of the tree to be measured
 *
 * Return: height of tree or 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves;

	if (tree == NULL)
		return (0);

	leaves = check(tree);

	return (leaves);
}
