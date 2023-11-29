#include "binary_trees.h"
/**
 * binary_tree_sibling - Function to find the sibling of a node.
 * @node: node to find the sibling of.
 *
 * Return: Returns the node to the sibling or NULL if not found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left_node, *right_node;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	left_node = node->parent->left;
	right_node = node->parent->right;
	if (left_node == NULL || right_node == NULL)
		return (NULL);
	if (left_node == node)
		return (right_node);
	return (left_node);
}
