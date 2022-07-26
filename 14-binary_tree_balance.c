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
	return (_height(tree) - 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root.
 * Return: balance factor or 0 if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_balance, r_balance, balance = 0;

	if (!tree)
		return (balance);

	l_balance = binary_tree_height(tree->left);
	r_balance = binary_tree_height(tree->right);
	balance = (l_balance - r_balance);

	return (balance);
}
