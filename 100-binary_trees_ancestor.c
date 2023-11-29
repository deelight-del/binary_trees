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

/**
 * search_common_ancestor - Function to search for the common ancestor
 * when both nodes are of the same depth
 * @first: First node
 * @second: Second node.
 *
 * Return: The given node, or NULL.
 */
binary_tree_t *search_common_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t const *first_ancestor, *second_ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	first_ancestor = first;
	second_ancestor = second;
	while (first_ancestor && second_ancestor)
	{
		if (first_ancestor == second_ancestor)
			return ((binary_tree_t *) (first_ancestor));
		first_ancestor = first_ancestor->parent;
		second_ancestor = second_ancestor->parent;
	}
	return (NULL);
}
/**
 * binary_trees_ancestor - Function to find the common ancestor between two
 * nodes generally.
 * @first: The first node to test.
 * @second: The second node to test.
 *
 * Return: A binary_tree pointer or NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;
	binary_tree_t *ancestor, *common_ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	if (first_depth == second_depth)
		return (search_common_ancestor(first, second));
	if (first_depth > second_depth)
	{
		ancestor = first->parent;
		while (binary_tree_depth(ancestor) > second_depth)
			ancestor = ancestor->parent;
		common_ancestor = search_common_ancestor(ancestor, second);
	}
	else
	{
		ancestor = second->parent;
		while (binary_tree_depth(ancestor) > first_depth)
			ancestor = ancestor->parent;
		common_ancestor = search_common_ancestor(ancestor, first);
	}
	return (common_ancestor);
}
