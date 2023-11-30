#include "binary_trees.h"
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
			free(temp);
			parent->left = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
/**
 * binary_tree_insert_right - Function to insert a node, right of the parent
 * @parent: The parent node of the given node.
 * @value: The value of the new node.
 *
 * Return: A pointer to the new node created.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent != NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (new_node == NULL)
			return (NULL);
		if (parent->right == NULL)
			parent->right = new_node;
		else
		{
			temp = parent->right;
			new_node->right = binary_tree_node(new_node, temp->n);
			free(temp);
			parent->right = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
/**
 * bst_insert - Function to insert a value in a bst.
 * @tree: The root node to a bst.
 * @value: Value of the new node to insert.
 *
 * Return: A bst datatype.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *travel, *new_node;

	if (tree == NULL || (*tree) == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		return (new_node);
	}
	travel = (*tree);
	while (travel != NULL)
	{
		if (value < travel->n)
		{
			if (travel->left == NULL || value > travel->left->n)
				return (binary_tree_insert_left
						(travel, value));
			else
				travel = travel->left;
		}
		else if (value > travel->n)
		{
			if (travel->right == NULL || value < travel->right->n)
				return (binary_tree_insert_right
						(travel, value));
			else
				travel = travel->right;
		}
	}
	return (NULL);
}
