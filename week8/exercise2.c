#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include <time.h>
#include <string.h>

#define MAX_STRING 256

int main()
{
    TreeType p, tree = NULL;
    int i, n = 0;
    char prefix[MAX_STRING];
    srand(time(NULL));
    for (i = 0; i < 10; i++)
        InsertNode(rand() % 100, &tree);
    printf("pretty print:\n");
    strcpy(prefix, "    ");
    prettyprint(tree, prefix);
    printf("\n");
    do
    {
        printf("Enter key to search (-1 to quit):");
        scanf("%d", &n);
        p = Search(n, tree);
        if (p != NULL)
            printf("Key %d found on the tree\n", n);
        else
            InsertNode(n, &tree);
    } while (n != -1);

    return 0;
}