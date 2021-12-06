#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

void MakeNullTree(tree_type *T)
{
    T = NULL;
}
int EmptyTree(tree_type *T)
{
    return T == NULL;
}

tree_type *InitNode()
{
    tree_type *N = (tree_type *)malloc(sizeof(tree_type));
    N->left = NULL;
    N->right = NULL;
    N->element = 0;
    return N;
}

tree_type *LeftChild(tree_type *n)
{
    if (n != NULL)
        return n->left;
    else
        return NULL;
}
tree_type *RightChild(tree_type *n)
{
    if (n != NULL)
        return n->right;
    else
        return NULL;
}

tree_type *CreateNode(elm_type NewData)
{
    tree_type *N = InitNode();
    N->element = NewData;
    return N;
}

int IsLeaf(tree_type *n)
{
    if (n != NULL)
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
    else
        return -1;
}

int NumberOfNode(tree_type *T)
{
    if (EmptyTree(T))
        return 0;
    else
        return 1 + NumberOfNode(LeftChild(T)) +
               NumberOfNode(RightChild(T));
}

tree_type *CreateNode2(elm_type v, tree_type *l, tree_type *r)
{
    tree_type *N = InitNode();
    N->element = v;
    N->left = l;
    N->right = r;
    return N;
}

tree_type *AddLeft(tree_type *Tree, elm_type NewData)
{
    tree_type *NewNode = CreateNode(NewData);
    if (NewNode == NULL)
        return (NewNode);
    if (Tree == NULL)
        Tree = NewNode;
    else
    {
        tree_type *Lnode = Tree;
        Lnode->left = NewNode;
    }
    return (NewNode);
}

tree_type *AddRight(tree_type *Tree, elm_type NewData)
{
    tree_type *NewNode = CreateNode(NewData);
    if (NewNode == NULL)
        return (NewNode);
    if (Tree == NULL)
        Tree = NewNode;
    else
    {
        tree_type *Rnode = Tree;
        Rnode->right = NewNode;
    }
    return (NewNode);
}

int HeightOfBinaryTree(tree_type *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = HeightOfBinaryTree(node->left);
        right_side = HeightOfBinaryTree(node->right);
        if (left_side > right_side)
        {
            return left_side + 1;
        }
        else
            return right_side + 1;
    }
}

int NumberOfLeaf(tree_type *node)
{
    if (IsLeaf(node))
        return 1;
    else
    {
        if (node == NULL)
            return 0;

        return NumberOfLeaf(node->left) + NumberOfLeaf(node->right);
    }
}

int NumberOfInternalNodes(tree_type *node)
{
    if (node == NULL || IsLeaf(node))
        return 0;
    else
    {
        return 1 + NumberOfInternalNodes(node->left) + NumberOfInternalNodes(node->right);
    }
}

int NumberOfRightNodes(tree_type *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + NumberOfRightNodes(node->right);
}

void PrintInorder(tree_type *node)
{
    if (node != NULL)
    {
        // printf("l");
        PrintInorder(node->left);
        // printf("m");
        printf("%c", node->element);
        // printf("r");
        PrintInorder(node->right);
    }
}

void freetree(tree_type *tree)
{
    if (tree != NULL)
    {
        freetree(tree->left);
        freetree(tree->right);
        free((void *)tree);
    }
}