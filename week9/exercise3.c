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

typedef struct NodeTree
{
    phoneaddress Key;
    struct NodeTree *Left, *Right;
} NodeTreeType;
typedef NodeTreeType *TreeType;

typedef struct NodeQueue
{
    TreeType Element;
    struct NodeQueue *Next; //pointer to next element
};

typedef struct NodeQueue *Position;
typedef struct
{
    Position Front, Rear;
} QueueType;

void InsertNode(phoneaddress x, TreeType *Root)
{
    if (*Root == NULL)
    {
        *Root = (NodeTreeType *)malloc(sizeof(NodeTreeType));
        (*Root)->Key = x;
        (*Root)->Left = NULL;
        (*Root)->Right = NULL;
    }
    else if (strcmp(((*Root)->Key).name, x.name) > 0)
    {
        // printf("%s %s\n", ((*Root)->Key).name, x.name);
        InsertNode(x, &(*Root)->Left);
    }
    else if (strcmp(((*Root)->Key).name, x.name) < 0)
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
        printf("%s", tree->Key.name);
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

void MakeNullQueue(QueueType *Q)
{
    struct NodeQueue *Header;
    Header = (struct NodeQueue *)malloc(sizeof(struct NodeQueue));
    //Allocation Header
    Header->Next = NULL;
    (*Q).Rear = Header;
    (*Q).Front = Header;
}

int EmptyQueue(QueueType Q)
{
    return (Q.Front == Q.Rear);
}

void EnQueue(TreeType X, QueueType *Q)
{
    (*Q).Rear->Next = (struct NodeQueue *)malloc(sizeof(struct NodeQueue));
    (*Q).Rear = (*Q).Rear->Next;
    (*Q).Rear->Element = X;
    (*Q).Rear->Next = NULL;
}

TreeType DeQueue(QueueType *Q)
{
    TreeType tmp;
    if (!EmptyQueue(*Q))
    {
        Position T;
        T = (*Q).Front;
        (*Q).Front = (*Q).Front->Next;
        tmp = (*Q).Front->Element;
        free(T);
        return tmp;
    }
}

void breadth_first(TreeType node)
{
    QueueType queue; // queue of pointers
    MakeNullQueue(&queue);
    if (node != NULL)
    {
        EnQueue(node, &queue);
        // printf("ok\n");
        while (!EmptyQueue(queue))
        {
            // printf("ok\n");
            node = DeQueue(&queue);
            printf("%s\n", node->Key.name);
            if (node->Left != NULL)
                EnQueue(node->Left, &queue);
            if (node->Right != NULL)
                EnQueue(node->Right, &queue);
        }
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

    n = 6;

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
    strcpy(prefix, "   ");
    PrettyPrint(root, prefix);
    printf("\n");

    breadth_first(root);
    return 0;
}