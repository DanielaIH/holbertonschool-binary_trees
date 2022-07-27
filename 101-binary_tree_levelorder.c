#include "binary_trees.h"

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
 * print_level - prints the level
 * @tree: pointer to the root.
 * @func: pointer to a function to call for each node.
 * @level: level.
 * @tree_height: tree's height.
 */

void print_level(const binary_tree_t *tree, size_t level,
size_t tree_height, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == tree_height)
		func(tree->n);
	print_level(tree->left, level + 1, tree_height, func);
	print_level(tree->right, level + 1, tree_height, func);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root.
 * @func: pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height = binary_tree_height(tree), i;

	if (tree == NULL || func == NULL)
		return;

	for (i = tree_height; i > 0; i--)
		print_level(tree, i, tree_height, func);
	print_level(tree, 0, tree_height, func);
}
