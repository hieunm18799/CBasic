#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

tree_type *InfixFormToBinary(tree_type *tree, char *str);
int CheckOpera(char c);

int string_index = 1;
tree_type *tree;

void main()
{
    char express[] = "!a+(b-c)/d";

    MakeNullTree(tree);
    tree = CreateNode(express[0]);

    tree = InfixFormToBinary(tree, express);

    PrintInorder(tree);
}

tree_type *InfixFormToBinary(tree_type *tree, char *str)
{
    tree_type *cur_node = InitNode();
    cur_node = tree;

    if (tree == NULL)
        printf("tree is nULL\n");
    printf("while start\n");
    while (str[string_index] != ')' && str[string_index] != '\0')
    {
        printf("ok %d\n", str[string_index]);
        if ('a' <= str[string_index] && str[string_index] <= 'z')
        {
            printf("1\n");
            if (CheckOpera(str[string_index - 1]))
                AddRight(cur_node, str[string_index]);
            else
                cur_node = CreateNode(str[string_index]);
        }
        else if (str[string_index] == '(')
        {
            string_index++;
            if (CheckOpera(str[string_index - 2]) == 1)
                cur_node->right = InfixFormToBinary(cur_node->right, str);
            else
                cur_node->left = InfixFormToBinary(cur_node->left, str);
        }
        else
        {
            printf("2\n");
            tree = CreateNode2(str[string_index], cur_node, NULL);
            cur_node = tree;
        }
        string_index++;
        tree = cur_node;
        PrintInorder(tree);
        printf("\n");
    }
    printf("while end\n");
    return tree;
}

int CheckOpera(char c)
{
    if (c == '=')
        return 1;
    if (c == '+')
        return 1;
    if (c == '-')
        return 1;
    if (c == '/')
        return 1;
    if (c == '*')
        return 1;
    if (c == '!')
        return 1;
    return 0;
}