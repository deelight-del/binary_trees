#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_alt_height - Function that gets the height of a tree.
 * @tree: The node of the tree.
 *
 * Return: The height of a tree.
 */
int binary_alt_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);
	if (tree->right == NULL && tree->left == NULL)
		return (0);
	left_height = binary_alt_height(tree->left);
	right_height = binary_alt_height(tree->right);
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
	int left_height, right_height;
	int difference;

	printf("Here is segfault\n");
	if (tree == NULL)
		return (0);
	left_height = binary_alt_height(tree->left);
	right_height = binary_alt_height(tree->right);
	difference = (left_height - right_height);
	return (difference);
}
