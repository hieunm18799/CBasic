#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20
#define MAX_STRING 256

enum
{
    FAIL,
    SUCCESS
};

typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

typedef struct Node
{
    phoneaddress Key;
    struct Node *Left, *Right;
} NodeType;
typedef NodeType *TreeType;

void InsertNode(phoneaddress x, TreeType *Root)
{
    if (*Root == NULL)
    {
        *Root = (NodeType *)malloc(sizeof(NodeType));
        (*Root)->Key = x;
        (*Root)->Left = NULL;
        (*Root)->Right = NULL;
    }
    else if (strcmp(((*Root)->Key).email, x.email) > 0)
    {
        // printf("%s %s\n", ((*Root)->Key).name, x.name);
        InsertNode(x, &(*Root)->Left);
    }
    else if (strcmp(((*Root)->Key).email, x.email) < 0)
    {
        // printf("%s %s\n", ((*Root)->Key).name, x.name);
        InsertNode(x, &(*Root)->Right);
    }
}

void PrettyPrint(TreeType tree, char *prefix)
{
    char *prefixend = prefix + strlen(prefix);
    if (tree != NULL)
    {
        printf("%s", tree->Key.email);
        if (tree->Left != NULL)
            if (tree->Right == NULL)
            {
                printf("\304");
                strcat(prefix, "                    ");
            }
            else
            {
                printf("\302");
                strcat(prefix, "\263                   ");
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
        strcat(prefix, "                    ");
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
    FILE *fp;
    phoneaddress phonearr[MAX];
    TreeType root, tmp_treeType;
    char tmp[MAX_STRING];
    int i, n, irc; // return code
    int reval = SUCCESS;

    n = 3;

    //read from this file to array again
    if ((fp = fopen("book_inp.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    fclose(fp);

    for (i = 0; i < n; i++)
    {
        // printf("%s %s %s\n", phonearr[i].name, phonearr[i].tel, phonearr[i].email);
        InsertNode(phonearr[i], &root);
    }

    char prefix[MAX_STRING];

    printf("-----------------------------------------------------------------------------\n");
    printf("Pretty print:\n");
    strcpy(prefix, "    ");
    PrettyPrint(root, prefix);
    printf("\n");

    return 0;
}