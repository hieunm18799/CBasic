#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
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
    struct Node *Next;
} NodeType;
typedef NodeType *ListType;

void InsertNode(phoneaddress x, ListType *Root)
{
    if (*Root == NULL)
    {
        *Root = (NodeType *)malloc(sizeof(NodeType));
        (*Root)->Key = x;
        (*Root)->Next = NULL;
    }
    else
        InsertNode(x, &(*Root)->Next);
}

int insertionSort(ListType *root)
{
    int count = 0;
    ListType sorted = *root,
             current = (*root)->Next;

    while (current != NULL)
    {
        // printf("%s\n", current->Key.name);
        ListType next = sorted,
                 inserting = current;
        current = current->Next;

        if (strcmp(inserting->Key.name, next->Key.name) > 0)
        {
            count++;
            while (next->Next != NULL && strcmp(inserting->Key.name, next->Next->Key.name) > 0)
            {
                // printf("%s %s\n", inserting->Key.name, next->Next->Key.name);
                count++;
                next = next->Next;
            }
            // printf("%s %s\n", inserting->Key.name, next->Next->Key.name);
            if (next->Next != inserting)
            {
                inserting->Next = next->Next;
                next->Next = inserting;
            } else {
                next->Next = inserting;
                inserting->Next = NULL;
            }
        }
        else
        {
            inserting->Next = next;
            sorted = inserting;
        }
    }
    *root = sorted;
    return count;
}

void printList(ListType root)
{
    printf("%s", root->Key.name);
    root = root->Next;
    while (root != NULL)
    {
        printf("->%s", root->Key.name);
        root = root->Next;
    }
    printf("\n");
}

void freetree(ListType tree)
{
    if (tree != NULL)
    {
        freetree(tree->Next);
        free((void *)tree);
    }
}

int main(void)
{
    FILE *fp;
    phoneaddress phonearr[MAX_ARRAY_SIZE];
    ListType root, tmp_treeType;
    char tmp[MAX_STRING];
    int i, n, irc; // return code
    int reval = SUCCESS;

    n = 10;

    root = NULL;
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

    printList(root);

    i = insertionSort(&root);

    printf("Sorted book phone after %d comparisons!\n", i);
    printList(root);
    return 0;
}