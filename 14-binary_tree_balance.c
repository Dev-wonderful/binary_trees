#include <stdlib.h>
#include "binary_trees.h"

/**
 * check - looks for longest path
 * @node: the tree to be checked
 *
 * Return: returns a value representing height
 */
size_t check_height(const binary_tree_t *node)
{
	size_t height = 1;
	size_t left, right;

	if (node->left != NULL)
		left = check_height(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = check_height(node->right);
	else
		right = 0;

	if (left >= right)
		height += left;
	else
		height += right;

	return (height);
}
/**
 * binary_tree_balance - find the balance of a tree
 * @tree: the tree to be checked
 *
 * Return: the balance value
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;
	int balance;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = check_height(tree->left);
	else
		left = 0;
	
	if (tree->right != NULL)
		right = check_height(tree->right);
	else
		right = 0;

	balance = left - right;
	
	return (balance);
}
