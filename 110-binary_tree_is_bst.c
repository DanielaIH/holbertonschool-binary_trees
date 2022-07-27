#include "binary_trees.h"
#include <limits.h>

/**
 * checkBST - checks if a binary tree is a valid BST.
 * @node: pointer to the node of the tree to check.
 * @min: INT_MIN.
 * @max: INT_MAX.
 * Return: 1 if it is BST, 0 otherwise.
 */

int checkBST(binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (checkBST(node->left, min, node->n - 1) &&
	checkBST(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if it is BST, 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (checkBST((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
