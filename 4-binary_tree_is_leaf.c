#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Function to test if a given node of a tree is a leaf.
 * @node: The node to test.
 *
 * Return: 1 if node, otherwise 0.
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
