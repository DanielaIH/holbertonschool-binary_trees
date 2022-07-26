#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least
 * 1 child in a binary tree.
 * @tree: pointer to the root.
 * Return: nodes with a child.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parents = 0;

	if (!tree)
		return (parents);

	if ((tree->right || tree->left))
		return (1 + binary_tree_nodes(tree->left)
		+ binary_tree_nodes(tree->right));

	return (parents);
}
