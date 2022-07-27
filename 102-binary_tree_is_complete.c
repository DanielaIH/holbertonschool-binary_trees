#include "binary_trees.h"
#include <stdbool.h>

/**
 * countNumNodes - counts the number of nodes.
 * @tree: pointer to the root.
 * Return: number of nodes.
 */

int countNumNodes(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + countNumNodes(tree->left) + countNumNodes(tree->right));
}

/**
 * checkComplete - checks if a binary tree is complete.
 * @tree: pointer to the root.
 * @index: index.
 * @numberNodes: number of nodes.
 * Return: true if complete.
 */

bool checkComplete(binary_tree_t *tree, int index, int numberNodes)
{
	if (tree == NULL)
		return (true);

	if (index >= numberNodes)
		return (false);

	return (checkComplete(tree->left, 2 * index + 1, numberNodes)
	&& checkComplete(tree->right, 2 * index + 2, numberNodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root.
 * Return: 1 if it is complete or 0 if tree is null or not perfect.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	int node_count = countNumNodes((binary_tree_t *)tree);

	if (tree == NULL)
		return (0);

	if (checkComplete((binary_tree_t *)tree, index, node_count))
		return (1);
	else
		return (0);
}
