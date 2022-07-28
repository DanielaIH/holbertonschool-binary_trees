#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *tmp;

	tmp = *tree;

	if (!tmp)
	{
		new_node = malloc(sizeof(bst_t));
		if (!new_node)
			return (NULL);
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->n = value;
		return (new_node);
	}

	if (value < tmp->n)
		(*tree)->left = bst_insert(&tmp->left, value);
	else if (value > tmp->n)
		(*tree)->right = bst_insert(&tmp->right, value);
	return (tmp);
}
