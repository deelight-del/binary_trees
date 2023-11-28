#include "binary_trees.h"
/**
 * binary_tree_is_full - Function to test if the binary tree is full
 * @tree: Root node.
 *
 * Return: 1, if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_right, is_full_left;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if ((tree->right == NULL && tree->left != NULL) ||
			(tree->left == NULL && tree->right != NULL))
		return (0);
	is_full_right = binary_tree_is_full(tree->right);
	is_full_left = binary_tree_is_full(tree->left);
	return (is_full_right * is_full_left);
}
