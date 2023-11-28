#include "binary_trees.h"
/**
 * binary_tree_leaves - Function to count all of the leaves int eh binarytree.
 * @tree: pointer to the root node.
 *
 * Return: A size_t object.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l_leaves, r_leaves;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	l_leaves = binary_tree_leaves(tree->left);
	r_leaves = binary_tree_leaves(tree->right);
	return (l_leaves + r_leaves);
}
