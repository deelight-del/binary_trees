#include "binary_trees.h"
/**
 * binary_tree_node - Function that creates a binary tree node.
 * @parent: pointer to the parent node of the node to create.
 * @value: The value of the node to create.
 *
 * Return: A binary_tree  node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
