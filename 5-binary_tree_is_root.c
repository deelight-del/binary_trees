#include "binary_trees.h"
/**
 * binary_tree_is_root - Funtion to check if a given node is root.
 * @node: The node to test for,
 *
 * Return: 1 if node is root, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	else
		return (0);
}
