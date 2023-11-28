#include "binary_trees.h"
/**
 * binary_tree_height - Function that gets the height of a tree.
 * @tree: The node of the tree.
 *
 * Return: The height of a tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (-1);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (right_height >= left_height)
		return (right_height + 1);
	else
		return (left_height + 1);
}
