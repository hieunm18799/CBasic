#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

typedef struct
{
    char name[MAX_LEN + 1];
    char phone[MAX_LEN + 1];
    char mail[MAX_LEN + 1];
} Eltype;

typedef struct queueNode
{
    Eltype data;
    struct queueNode *link;
} queueList;

typedef struct
{
    queueList *Front, *Rear;
} Queue;

void MakeNullQueue(Queue *Q)
{
    queueList *Header;
    Header = (queueList *)malloc(sizeof(queueList));
    //Allocation Header
    Header->link = NULL;
    Q->Front = Header;
    Q->Rear = Header;
}

int EmptyQueue(Queue Q)
{
    return (Q.Front == Q.Rear);
}

Queue *EnQueue(Eltype X, Queue *Q)
{
    Q->Rear->link = (queueList *)malloc(sizeof(queueList));
    Q->Rear = Q->Rear->link;
    Q->Rear->data = X;
    Q->Rear->link = NULL;
    return Q;
}

Queue *DeQueue(Eltype *X, Queue *Q)
{
    if (!EmptyQueue(*Q))
    {
        queueList *T;
        Q->Front = Q->Front->link;
        T = Q->Front;
        *X = T->data;
        free(T);
    }
    return Q;
}

void copy_file(FILE *fin, FILE *fout);

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;

    if (argc != 3)
    {
        printf("The correct syntax should be: ./exercise3 <filename1> <filename2>\n");
        reval = FAIL;
        exit(0);
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", fptr1);
        reval = FAIL;
        exit(0);
    }
    else if ((fptr2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open %s.\n", fptr2);
        reval = FAIL;
        exit(0);
    }
    else
    {
        copy_file(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}

void copy_file(FILE *fin, FILE *fout)
{
    Queue *queueBookFile;
    Eltype tmp;
    
    MakeNullQueue(queueBookFile);
    while (!feof(fin))
    {
        fscanf(fin, "%s %s %s", tmp.name, tmp.phone, tmp.mail);

        //printf("%s %s %s\n", tmp.name, tmp.phone, tmp.mail);
        queueBookFile = EnQueue(tmp, queueBookFile);
    }

    while (!EmptyQueue(*queueBookFile)) {
        queueBookFile = DeQueue(&tmp, queueBookFile);
        //printf("%s %s %s\n", tmp.name, tmp.phone, tmp.mail);
        fprintf(fout, "%s %s %s\n", tmp.name, tmp.phone, tmp.mail);
    }
}