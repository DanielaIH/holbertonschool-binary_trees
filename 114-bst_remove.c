#include "binary_trees.h"

/**
 * minValueNode - finds the min value in a tree.
 * @node: pointer to a node of the tree.
 * Return: the node with the lowest value.
 */
bst_t *minValueNode(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left)
        current = current->left;
    return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @tree: pointer to the root node of the tree where you will remove a node.
 * @value: the value to remove in the tree.
 * Return: pointer to the new root node of the tree after removing the desired value.
 * Null otherwise.
 */

bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (root == NULL)
        return root;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    if (value > root->n)
        root->right = bst_remove(root->right, value);
    if (value == root->n)
    {
        if (!root->left) 
        {
            temp = root->right;
            if (root->parent)
            {
                temp->parent = root->parent;
                root->parent->right = temp;
            }
            binary_tree_delete(root);
            return (temp);
        }
        else if (!root->right) 
        {
            temp = root->left;
            if (root->parent)
            {
                temp->parent = root->parent;
                root->parent->right = temp;
            }
            binary_tree_delete(root);
            return (temp);
        }
        else
        {
            temp = minValueNode(root->right);
            root->n = temp->n;
            if(temp->right)
            {
                temp->right->parent = temp->parent;
                temp->parent->left = temp->right;
            }
            binary_tree_delete(temp);
            return (root);
        }
    }
    return (root);
}
