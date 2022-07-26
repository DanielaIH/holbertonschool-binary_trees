#include "binary_trees.h"
#include <stdbool.h>

/**
 * _depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the root.
 * Return: Depth.
 */

int _depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * bt_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root.
 * @d: tree's depth.
 * @level: level.
 * Return: 1 if it is perfect or 0 if tree is null or not perfect.
 */

bool bt_is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (false);

	if (!tree->left && !tree->right)
	{
		if (d == level + 1)
			return (true);
	}

	if (!tree->left || !tree->right)
	{
		return (false);
	}

	level++;

	return (bt_is_perfect(tree->left, d, level) &&
	bt_is_perfect(tree->right, d, level));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root.
 * Return: 1 if it is perfect or 0 if tree is null or not perfect.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = _depth(tree);

	if ((bt_is_perfect(tree, d, 0)) == true)
		return (1);
	else
		return (0);
}
