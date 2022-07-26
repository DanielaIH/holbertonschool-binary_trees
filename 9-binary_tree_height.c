#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using
 * post-order traversal
 * @tree: pointer to the root.
 * @func: pointer to a function to call for each node.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left = 0, height_right = 0;
    const binary_tree_t *current;

    if (!tree)
        return (height_left);
    
    current = tree;
    while (current->left)
    {
        current = current->left;
        height_left++;
    }
    current = tree;
    while(current->right)
    {
        current = current->right;
        height_right++;
    }
    if (height_left > height_right)
        return (height_left);
    return (height_right);
}