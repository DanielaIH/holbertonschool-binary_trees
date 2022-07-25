#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: Nothing.
 */

 void binary_tree_delete(binary_tree_t *tree)
 {
    if (tree == NULL)
        return;
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
/*    if (tree->left)
        free(tree->left);
    if (tree->right)
        free(tree->right);
    if (tree->left == NULL && tree->right == NULL) */
    printf("Node to delete %d\n", tree->n); /* BORRAR */
    free(tree);
 }