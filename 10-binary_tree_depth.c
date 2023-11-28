#include "binary_trees.h"
/**
 * binary_tree_depth - The function to calculate the depth of a given node
 * @tree: Node of the tree.
 *
 * Return: size_t value.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *parent;
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	parent = tree->parent;
	while (parent)
	{
		parent = parent->parent;
		depth++;
	}
	return (depth);
}
