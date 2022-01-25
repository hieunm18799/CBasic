#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void MakeNullSet(Dictionary D)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        D[i] = NULL;
}

int emptybucket(Dictionary D, int b)
{
    return (D[b] == NULL ? 1 : 0);
}

int empty(Dictionary D)
{
    int b;
    for (b = 0; b < ARRAY_SIZE; b++)
        if (D[b] != NULL)
            return 0;
    return 1;
}

void clearbucket(Dictionary D, int b)
{
    Position p, q;
    q = NULL;
    p = D[b];
    while (p != NULL)
    {
        q = p;
        p = p->Next;
        free(q);
    }
    D[b] = NULL;
}

void clear(Dictionary D)
{
    int b;
    for (b = 0; b < ARRAY_SIZE; b++)
        clearbucket(b, D);
}

void InsertSet(Dictionary D, KeyType X)
{
    int Bucket;
    Position P;
    if (!Member(X, D))
    {
        Bucket = H(X);
        P = D[Bucket];
        // allocate a new node at D[Bucket]
        D[Bucket] = (Node *)malloc(sizeof(Node));
        D[Bucket]->Key = X;
        D[Bucket]->Next = P;
    }
}

void DeleteSet(Dictionary D, KeyType X)
{
    int Bucket, Done;
    Position P, Q;
    Bucket = H(X);
    // If list has already existed
    if (D[Bucket] != NULL)
    {
        // if X at the head of the list
        if (D[Bucket]->Key == X)
        {
            Q = D[Bucket];
            D[Bucket] = D[Bucket]->Next;
            free(Q);
        }
        else
        { // Search for X
            Done = 0;
            P = D[Bucket];
            while ((P->Next != NULL) &&
                   (!Done))
                if (P->Next->Key == X)
                    Done = 1;
                else
                    P = P->Next;
            if (Done)
            { // If found
                // Delete P->Next
                Q = P->Next;
                P->Next = Q->Next;
                free(Q);
            }
        }
    }
}

int Search(Dictionary D, KeyType X)
{
    Position P;
    int Found = 0;
    // Go to bucket at H(X)
    P = D[H(X)];
    // Traverse through the list at bucket H(X)
    while ((P != NULL) && (!Found))
        if (P->Key == X)
            Found = 1;
        else
            P = P->Next;
    return Found;
}

void traversebucket(Dictionary D, int b)
{
    Position p;
    p = D[b];
    while (p != NULL)
    {
        // Assume that the key is of int type
        printf("%3d", p->Key);
        p = p->Next;
    }
}

void traverse(Dictionary D)
{
    int b;
    for (b = 0; b < ARRAY_SIZE; b++)
    {
        printf("\nBucket %d:", b);
        traversebucket(b, D);
    }
}