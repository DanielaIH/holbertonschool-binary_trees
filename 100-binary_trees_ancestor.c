#include "binary_trees.h"

binary_tree_t *lca(const binary_tree_t *root, const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *left, *right;
	binary_tree_t *tmp;

	tmp = (binary_tree_t *) root;

	if (tmp == NULL)
		return (NULL);

	if (tmp == first || tmp == second)
		return (tmp);

	left = lca(tmp->left, first, second);
	right = lca(tmp->right, first, second);

	if (left && right)
		return (tmp);
	return ((left) ? left : right);
}

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes.
 * @first: first node.
 * @second: second node.
 * Return: a pointer to the lowest common ancestor node, otherwise NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *root1 = first;
	const binary_tree_t *root2 = second;

	if (!first || !second)
		return (NULL);
	while (root1->parent)
	{
		root1 = root1->parent;
	}
	while (root2->parent)
	{
		root2 = root2->parent;
	}
	if (root1 != root2)
		return (NULL);

	return (lca(root1, first, second));
}
