#include "binary_trees.h"
#include <limits.h>

/**
 * _height - measures the height of a binary tree by nodes.
 * @tree: pointer to the root.
 * Return: the height or 0 if tree is null.
 */

size_t _height(const binary_tree_t *tree)
{
	size_t lt_height, rt_height;

	if (tree == NULL)
		return (0);
	lt_height = _height(tree->left) + 1;
	rt_height = _height(tree->right) + 1;
	if (lt_height > rt_height)
		return (lt_height);
	else
		return (rt_height);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root.
 * Return: the height or 0 if tree is null.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_height(tree) - 1);
}

/**
 * checkAVL - checks if a binary tree is a valid BST.
 * @node: pointer to the node of the tree to check.
 * @min: INT_MIN.
 * @max: INT_MAX.
 * Return: 1 if it is BST, 0 otherwise.
 */

int checkAVL(binary_tree_t *node, int min, int max)
{
    size_t left_height, right_height;
	if (!node)
		return (1);

	if (node->n < min || node->n > max)
		return (0);
    
    left_height = binary_tree_height(node->left);
    right_height = binary_tree_height(node->right);
    if ((left_height - right_height > 1) || (right_height - left_height > 1))
    {
        return (0);
    }
	return (checkAVL(node->left, min, node->n - 1) &&
	checkAVL(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if it is BST, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (checkAVL((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
