#include "binary_trees.h"
/**
 * binary_tree_inorder - Function to traverse tree inorder.
 * @tree: The root node of the tree.
 * @func: The function to accept integer to print from.
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
