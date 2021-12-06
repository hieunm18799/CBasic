#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20
#define MAX_STRING 256

enum
{
    FAIL,
    SUCCESS
};

typedef struct
{
    char word[MAX_STRING];
    int count;
} wordcount;

typedef struct Node
{
    wordcount Key;
    struct Node *Left, *Right;
} NodeType;
typedef NodeType *TreeType;

TreeType Search(char *word, TreeType Root)
{
    if (Root == NULL)
        return NULL; // not found
    else if (strcmp((Root->Key).word, word) == 0)
        return Root;
    else if (strcmp((Root->Key).word, word) < 0)
        //continue searching in the Right sub tree
        return Search(word, Root->Right);
    else
    {
        // continue searching in the Left sub tree
        return Search(word, Root->Left);
    }
}

void InsertNode(char *x, TreeType *Root)
{
    // printf("ok\n");
    if (*Root == NULL)
    {
        // printf("ok\n");
        *Root = (NodeType *)malloc(sizeof(NodeType));
        strcpy((*Root)->Key.word, x);
        (*Root)->Key.count = 1;
        (*Root)->Left = NULL;
        (*Root)->Right = NULL;
    }
    else if (strcmp(((*Root)->Key).word, x) > 0)
    {
        // printf("%s %s\n", ((*Root)->Key).word, x);
        InsertNode(x, &(*Root)->Left);
    }
    else if (strcmp(((*Root)->Key).word, x) < 0)
    {
        // printf("%s %s\n", ((*Root)->Key).word, x);
        InsertNode(x, &(*Root)->Right);
    }
    else
        (*Root)->Key.count++;
}

void PrettyPrint(TreeType tree, char *prefix)
{
    char *prefixend = prefix + strlen(prefix);
    if (tree != NULL)
    {
        printf("%s", tree->Key.word);
        if (tree->Left != NULL)
            if (tree->Right == NULL)
            {
                printf("\304");
                strcat(prefix, "    ");
            }
            else
            {
                printf("\302");
                strcat(prefix, "\263   ");
            }

        PrettyPrint(tree->Left, prefix);
        *prefixend = '\0';
        if (tree->Right != NULL)
            if (tree->Left != NULL)
            {
                printf("\n%s", prefix);
                printf("\300");
            }
            else
                printf("\304");
        strcat(prefix, "    ");
        PrettyPrint(tree->Right, prefix);
    }
}

void freetree(TreeType tree)
{
    if (tree != NULL)
    {
        freetree(tree->Left);
        freetree(tree->Right);
        free((void *)tree);
    }
}

int main(void)
{
    TreeType root, tmp_treeType;
    char tmp[MAX_STRING];
    int reval = SUCCESS;
    char string[] = "A black black cat saw a very small mouse and a very scared mouse";
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }

    root = NULL;
    char *token = strtok(string, " ");
    while (token != NULL)
    {
        InsertNode(token, &root);
        token = strtok(NULL, " ");
    }

    char prefix[MAX_STRING];

    printf("-----------------------------------------------------------------------------\n");
    printf("Pretty print:\n");
    strcpy(prefix, "   ");
    PrettyPrint(root, prefix);
    printf("\n");

    printf("-----------------------------------------------------------------------------\n");
    printf("Searching word!\n");
    do
    {
        printf("-----------------------------------------------------------------------------\n");
        printf("Enter word to search:");
        scanf("%s", tmp);
        tmp_treeType = Search(tmp, root);
        if (tmp_treeType != NULL)
            printf("Word %s's frequencies is %d!\n", tmp_treeType->Key.word, tmp_treeType->Key.count);
        else
            printf("Not found!\n");

    } while (tmp != '\n');

    return 0;
}