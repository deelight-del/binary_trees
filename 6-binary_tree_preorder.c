#include "binary_trees.h"
/**
 * binary_tree_preorder - Function to traverse the tree in preorder trav.
 * @tree: pointer to root node.
 * @func: pointer to function.
 *
 * Return: void.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
