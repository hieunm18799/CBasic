#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 256
typedef struct
{
    double time;
    char place[MAX_STRING + 1];
    char people[MAX_STRING + 1];
    char description[MAX_STRING + 1];
} ElementType;
typedef struct Node
{
    ElementType Element;
    struct Node *Next; //pointer to next element
} Node;

typedef struct Node *Position;
typedef struct
{
    Position Front, Rear;
} Queue;

void MakeNullQueue(Queue *Q)
{
    Position Header;
    Header = (struct Node *)malloc(sizeof(struct Node));
    //Allocation Header
    Header->Next = NULL;
    Q->Front = Header;
    Q->Rear = Header;
}

int EmptyQueue(Queue Q)
{
    return (Q.Front == Q.Rear);
}

void EnQueue(ElementType X, Queue *Q)
{
    Q->Rear->Next =
        (struct Node *)malloc(sizeof(struct Node));
    Q->Rear = Q->Rear->Next;
    Q->Rear->Element = X;
    Q->Rear->Next = NULL;
}

void DeQueue(Queue *Q)
{
    if (!EmptyQueue(*Q))
    {
        Position T;
        T = Q->Front;
        Q->Front = Q->Front->Next;
        free(T);
    }
    else
        printf("Error: Queue is empty.");
}

int modifyQueue(ElementType X, Queue *Q);
void printTodo(Queue *Q);

Queue todoQueueList;

int main()
{
    int choice;
    char tmp[MAX_STRING + 1];
    ElementType eleTmp;

    MakeNullQueue(&todoQueueList);

    do
    {
        printf("Todo's list:\n");
        printTodo(&todoQueueList);

        printf("Menu!\n");
        printf("1.Adding!\n");
        printf("2.Deleting!\n");
        printf("3.Modifying!\n");
        printf("0.Exit\n");
        printf("Your choice:");
        scanf("%d", &choice);
        printf("-------------------------------------------\n");
        switch (choice)
        {
        case 1:
            printf("Adding todo!\n");
            printf("Place: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.place, tmp);
            printf("People: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.people, tmp);
            printf("Description: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.description, tmp);
            eleTmp.time = (double)clock() / CLOCKS_PER_SEC;

            printf("ok\n");
            EnQueue(eleTmp, &todoQueueList);

            printf("-------------------------------------------\n");
            break;
        case 2:
            printf("Deleting todo!\n");

            DeQueue(&todoQueueList);

            printf("-------------------------------------------\n");
            break;
        case 3:
            printf("Modifying todo!\n");

            printf("Find and modify by people: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.people, tmp);
            printf("Place: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.place, tmp);
            printf("Description: ");
            scanf("%100s", tmp);
            strcpy(eleTmp.description, tmp);

            modifyQueue(eleTmp, &todoQueueList);
            printf("-------------------------------------------\n");
            break;
        case 0:
            printf("Exit program!\n");
            printf("-------------------------------------------\n");
            break;
        default:
            printf("Your choice is wrong!\n");
            printf("-------------------------------------------\n");
            break;
        }
    } while (choice != 0);
}

int modifyQueue(ElementType X, Queue *Q)
{
    Position tmpPos = Q->Front;

    do
    {
        if (strcmp(X.people, tmpPos->Element.people) == 0)
        {
            strcpy(tmpPos->Element.place, X.place);
            strcpy(tmpPos->Element.description, X.description);
            return 1;
        }
        tmpPos = tmpPos->Next;
    } while (tmpPos != NULL);
    return 0;
}

void printTodo(Queue *Q)
{
    Position tmpPos = Q->Front->Next;

    while (tmpPos != NULL)
    {
        printf("%s %s %s %lf\n", tmpPos->Element.people, tmpPos->Element.place, tmpPos->Element.description, tmpPos->Element.time);
        tmpPos = tmpPos->Next;
    }
}