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

	if (binary_is_leaf(tree) == 1)
		return (1);
	else
	{
		l_leaves = binary_tree_leaves(tree->left);
		r_leaves = binary_tree_leaves(tree->right);
		return (l_leaves + r_leaves);
	}
}

/**
 * binary_tree_is_leaf - Function to test if a given node of a tree is a leaf.
 * @node: The node to test.
 *
 * Return: 1 if node, otherwise 0.
 */
int binary_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (-1);
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
