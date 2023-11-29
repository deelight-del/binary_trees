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
 * binary_tree_print_level - Function to print a tree at a given level.
 * @tree: The root node to the tree.
 * @level: The level to print at.
 * @func: The function that prints.
 *
 * Return: void.
 */
void binary_tree_print_level(const binary_tree_t *tree,
		size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_print_level(tree->left, level - 1, func);
		binary_tree_print_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - Function to print all nodes in a tree, levelorder.
 * @tree: node to the root node.
 * @func: Functio to print node.
 *
 * Return: void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (level = 0; level <= height; level++)
	{
		binary_tree_print_level(tree, level, func);
	}
}
