#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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