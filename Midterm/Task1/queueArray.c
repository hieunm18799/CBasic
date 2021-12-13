#include <stdio.h>
#include "queueArray.h"

void MakeNull_Queue(QueueArray *Q)
{
    Q->Front = -1;
    Q->Rear = -1;
}
int Empty_Queue(QueueArray Q)
{
    return Q.Front > Q.Rear;
}
int Full_Queue(QueueArray Q)
{
    return (Q.Front == Q.Rear);
}

void EnQueue(ElementType X, QueueArray *Q)
{
    Q->Rear = (Q->Rear + 1) % MaxLength;
    if (Full_Queue(*Q)) {
        Q->Front = (Q->Front + 1) % MaxLength;
        printf("The address's name %s, phone %s, email %s has been removed!\n", Q->Elements[Q->Front].name, Q->Elements[Q->Front].phone, Q->Elements[Q->Front].mail);
    }
    Q->Elements[Q->Rear] = X;
    // printf("%d %d\n", Q->Front, Q->Rear);
}

ElementType DeQueue(QueueArray *Q)
{
    Q->Front = (Q->Front + 1) % MaxLength;
    return Q->Elements[Q->Front];
}