#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_insert_left - Function to insert a node, left of the parent
 * @parent: The parent node of the given node.
 * @value: The value of the new node.
 *
 * Return: A pointer to the new node created.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent != NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (new_node == NULL)
			return (NULL);
		if (parent->left == NULL)
			parent->left = new_node;
		else
		{
			temp = parent->left;
			new_node->left = binary_tree_node(new_node, temp->n);
			parent->left = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
