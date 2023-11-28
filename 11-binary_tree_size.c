#include "binary_trees.h"
/**
 * binary_tree_size - Calculate the size of a node.
 * @tree: pointer to the root node.
 *
 * Return: size_t value.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_count, r_count;

	if (tree == NULL)
		return (0);
	l_count = binary_tree_size(tree->left);
	r_count = binary_tree_size(tree->right);
	return (l_count + r_count + 1);
}
