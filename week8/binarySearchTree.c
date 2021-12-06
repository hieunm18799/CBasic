#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include <string.h>

TreeType Search(KeyType x, TreeType Root)
{
    if (Root == NULL)
        return NULL;         // not found
    else if (Root->key == x) /* found x */
        return Root;
    else if (Root->key < x)
        //continue searching in the right sub tree
        return Search(x, Root->right);
    else
    {
        // continue searching in the left sub tree
        return Search(x, Root->left);
    }
}

void InsertNode(KeyType x, TreeType *Root)
{
    if (*Root == NULL)
    {
        /* Create a new node for key x */
        *Root = (NodeType *)malloc(sizeof(NodeType));
        (*Root)->key = x;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
    }
    else if (x < (*Root)->key)
        InsertNode(x, &(*Root)->left);
    else if (x > (*Root)->key)
        InsertNode(x, &(*Root)->right);
}

KeyType DeleteMin(TreeType *Root)
{
    KeyType k;
    if ((*Root)->left == NULL)
    {
        k = (*Root)->key;
        (*Root) = (*Root)->right;
        return k;
    }
    else
        return DeleteMin(&(*Root)->left);
}

void DeleteNode(KeyType X, TreeType *Root)
{
    if (*Root != NULL)
        if (X < (*Root)->key)
            DeleteNode(X, &(*Root)->left);
        else if (X > (*Root)->key)
            DeleteNode(X, &(*Root)->right);
        else if ((*Root)->left == NULL && (*Root)->right == NULL)
            *Root = NULL;
        else if ((*Root)->left == NULL)
            *Root = (*Root)->right;
        else if ((*Root)->right == NULL)
            *Root = (*Root)->left;
        else
            (*Root)->key = DeleteMin(&(*Root)->right);
}

void prettyprint(TreeType tree, char *prefix)
{
    char *prefixend = prefix + strlen(prefix);
    if (tree != NULL)
    {
        printf("%04d", tree->key);
        if (tree->left != NULL)
            if (tree->right == NULL)
            {
                printf("\304");
                strcat(prefix, "     ");
            }
            else
            {
                printf("\302");
                strcat(prefix, "\263    ");
            }

        prettyprint(tree->left, prefix);
        *prefixend = '\0';

        if (tree->right != NULL)
            if (tree->left != NULL)
            {
                printf("\n%s", prefix);
                printf("\300");
            }
            else
                printf("\304");
        strcat(prefix,"     ");
        prettyprint(tree->right, prefix);
    }
}

void freetree(TreeType tree)
{
    if (tree != NULL)
    {
        freetree(tree->left);
        freetree(tree->right);
        free((void *)tree);
    }
}