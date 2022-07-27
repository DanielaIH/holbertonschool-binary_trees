#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the root.
 * Return: Depth.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current = tree;
	size_t depth = 0;

	if (!tree)
		return (0);

	while (current->parent)
	{
		current = current->parent;
		depth++;
	}
	return (depth);
}
