#include "binary_trees.h"
/**
 * binary_tree_delete - Function to delete entire tree.
 * @tree: Node to given tree.
 *
 * Return: void.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left_tree = NULL, *right_tree = NULL;

	if (tree == NULL)
		return;
	if (tree->right != NULL)
		right_tree = tree->right;
	if (tree->left != NULL)
		left_tree = tree->left;
	free(tree);
	binary_tree_delete(right_tree);
	binary_tree_delete(left_tree);
}
