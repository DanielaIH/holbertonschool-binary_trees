#include "binary_trees.h"

/**
 * _bst_insert2 - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
 */

bst_t *_bst_insert2(bst_t **tree, int value)
{
	bst_t *tmp;

	tmp = *tree;

	if (value < tmp->n)
	{
		if (tmp->left)
			return (_bst_insert2(&(*tree)->left, value));
		tmp->left = binary_tree_node((*tree), value);
		return (tmp->left);
	}
	else if (value > tmp->n)
	{
		if (tmp->right)
			return (_bst_insert2(&(*tree)->right, value));
		tmp->right = binary_tree_node((*tree), value);
		return (tmp->right);
	}
	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (_bst_insert2(tree, value));
}
