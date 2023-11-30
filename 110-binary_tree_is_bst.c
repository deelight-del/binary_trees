#include "binary_trees.h"
#include <limits.h>
/**
 * is_bst_utils - Function to help determine of a given tree is bst or not.
 * @tree: The node to the root tree.
 * @min: The minimum value in a bound to compare our node value with.
 * @max: The maximum value in a bound to compare our node values with.
 *
 * Return: 0 or 1.
 */
int is_bst_utils(binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	left = is_bst_utils(tree->left, min, tree->n);
	right = is_bst_utils(tree->right, tree->n, max);
	return (left * right);
}
/**
 * binary_tree_is_bst - Check if a tree is a binary tree.
 * @tree: The pointer to the root node.
 *
 * Return: integer 0, or 1.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_bst, right_bst;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	left_bst = is_bst_utils(tree->left, INT_MIN, INT_MAX);
	right_bst = is_bst_utils(tree->right, INT_MIN, INT_MAX);
	return (left_bst * right_bst);
}
