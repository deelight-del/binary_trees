#include "binary_trees.h"
/**
 * binary_tree_height - Function that gets the height of a tree.
 * @tree: The node of the tree.
 *
 * Return: The height of a tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (right_height >= left_height)
		return (right_height + 1);
	else
		return (left_height + 1);
}

/**
 * binary_tree_balance - Function to find the balance of a tree.
 * @tree: The root node of a tree.
 *
 * Return: An integer
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *left_tree, *right_tree;
	size_t left_height, right_height;
	int difference;

	if (tree == NULL)
		return (0);
	left_tree = tree->left;
	right_tree = tree->right;
	left_height = binary_tree_height(left_tree);
	right_height = binary_tree_height(right_tree);
	difference = ((int)left_height) - ((int)right_height);
	return (difference);
}
