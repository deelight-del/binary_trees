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

/**
 * binary_tree_nodes - Calculate the total nodes except for leaf nodes.
 * @tree: pointer to the root node.
 *
 * Return: A size_t value.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t total_nodes, leaf_nodes;

	total_nodes = binary_tree_size(tree);
	leaf_nodes = binary_tree_leaves(tree);
	return (total_nodes - leaf_nodes);
}
