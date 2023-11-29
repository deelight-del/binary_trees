#include "binary_trees.h"
/**
 * binary_tree_is_full - Function to test if the binary tree is full
 * @tree: Root node.
 *
 * Return: 1, if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_right, is_full_left;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if ((tree->right == NULL && tree->left != NULL) ||
			(tree->left == NULL && tree->right != NULL))
		return (0);
	is_full_right = binary_tree_is_full(tree->right);
	is_full_left = binary_tree_is_full(tree->left);
	return (is_full_right * is_full_left);
}

/**
 * binary_tree_leaves_equal - Function to get if the depth of
 * the leaves in a bin_tree are equal.
 * @tree: A pointer to the node of the tree.
 *
 * Return: 1 if leaves are equal, 0 otherwise.
 */
int binary_tree_leaves_equal(const binary_tree_t *tree)
{
	int left_equalness, right_equalness;
	binary_tree_t *left_node, *right_node;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		return (1);
	if (binary_tree_is_leaf(tree) == 1 && tree->parent != NULL)
	{
		left_node = tree->parent->left;
		right_node = tree->parent->right;
		if (binary_tree_is_leaf(left_node) == 1 &&
				binary_tree_is_leaf(right_node) == 1)
			return (1);
		return (0);
	}
	left_equalness = binary_tree_leaves_equal(tree->left);
	right_equalness = binary_tree_leaves_equal(tree->right);
	return (left_equalness * right_equalness);

}
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
 * binary_tree_is_perfect - Function to chexk if tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: An integer 0 or 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int fullness, leaf_equalness;

	fullness = binary_tree_leaves_equal(tree);
	leaf_equalness = binary_tree_leaves_equal(tree);
	return (fullness * leaf_equalness);
}
