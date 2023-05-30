#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse the tree using preorder method
 * @tree: pointer to the tree
 * @func: pointer to a print function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
