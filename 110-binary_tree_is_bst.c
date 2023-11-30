#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_bst - Check if a tree is a binary tree.
 * @tree: The pointer to the root node.
 *
 * Return: integer 0, or 1.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_bst, right_bst, final_bst;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && (tree->left->n < tree->n)
			&& tree->right && (tree->n < tree->right->n))
	{
		left_bst = binary_tree_is_bst(tree->left);
		right_bst = binary_tree_is_bst(tree->right);
		final_bst = (left_bst * right_bst);
	}
	else
	{
		left_bst = binary_tree_is_bst(tree->left);
		right_bst = binary_tree_is_bst(tree->right);
		final_bst = (left_bst * right_bst);
	}
	return (final_bst);

}
