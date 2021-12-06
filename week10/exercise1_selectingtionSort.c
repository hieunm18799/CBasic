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

int selectionSort(ListType *root)
{
    int count = 0;
    ListType sorted = NULL,
             current = (*root);

    while (current != NULL)
    {
        // printList(current);
        ListType next,
                 selecting = current,
                 prevSelecting = NULL,
                 prevNext = NULL;
        next = current;
        while (next != NULL)
        {
            if (strcmp(selecting->Key.name, next->Key.name) < 0)
            {
                prevSelecting = prevNext;
                selecting = next;
            }

            // printf("%s %s\n", selecting->Key.name, next->Next->Key.name);
            count++;
            prevNext = next;
            next = next->Next;
        }

        if (prevSelecting != NULL)
        {
            prevSelecting->Next = selecting->Next;
        } else current = current->Next;
        if (sorted != NULL)
        {
            selecting->Next = sorted;
            sorted = selecting;
        }
        else
        {
            selecting->Next = NULL;
            sorted = selecting;
        }
        // printList(sorted);
    }
    *root = sorted;
    return count;
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

    i = selectionSort(&root);

    printf("Sorted book phone after %d comparisons!\n", i);
    printList(root);
    return 0;
}