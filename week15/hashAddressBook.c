#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashAddressBook.h"
#include "hashFunc.h"

bool cmpKey(KeyType X, KeyType Y)
{
    if (strcmp(X.email, Y.email) == 0 && strcmp(X.name, Y.name) == 0 && strcmp(X.tel, Y.tel) == 0)
        return true;
    return false;
}

void MakeNullSet(Dictionary D)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        D[i] = NULL;
}

int emptybucket(Dictionary D, int b)
{
    return (D[b] == NULL ? 1 : 0);
}

int empty(Dictionary D)
{
    int b;
    for (b = 0; b < TABLE_SIZE; b++)
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
    for (b = 0; b < TABLE_SIZE; b++)
        clearbucket(D, b);
}

bool Member(Dictionary D, KeyType X)
{
    int Bucket;
    Position P;

    Bucket = hash(X.email);

    P = D[Bucket];
    if (D[Bucket] != NULL)
    {
        // if X at the head of the list
        if (cmpKey(D[Bucket]->Key, X))
        {
            return true;
        }
        else
        { // Search for X
            P = D[Bucket];
            while ((P->Next != NULL) && !cmpKey(P->Next->Key, X))
                P = P->Next;
            if (cmpKey(P->Next->Key, X))
                return true;
            else
                return false;
        }
    }
    return false;
}

void InsertSet(Dictionary D, KeyType X)
{
    int Bucket;
    Position P;
    if (!Member(D, X))
    {
        Bucket = hash(X.email);

        P = D[Bucket];
        D[Bucket] = (Node *)malloc(sizeof(Node));
        D[Bucket]->Key = X;
        D[Bucket]->Next = P;
    }
}

void DeleteSet(Dictionary D, KeyType X)
{
    int Bucket, Done;
    Position P, Q;
    Bucket = hash(X.email);
    // If list has already existed
    if (D[Bucket] != NULL)
    {
        // if X at the head of the list
        if (cmpKey(D[Bucket]->Key, X))
        {
            Q = D[Bucket];
            D[Bucket] = D[Bucket]->Next;
            free(Q);
        }
        else
        { // Search for X
            Done = 0;
            P = D[Bucket];
            while ((P->Next != NULL) && (!Done))
                if (cmpKey(P->Next->Key, X))
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
    P = D[hash(X.email)];
    // Traverse through the list at bucket H(X)
    while ((P != NULL) && (!Found))
        if (cmpKey(P->Key, X))
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
        printf("->%s-%s-%s\n", p->Key.name, p->Key.email, p->Key.tel);
        p = p->Next;
    }
}

void traverse(Dictionary D)
{
    int b;
    printf("Hash table\n");
    for (b = 0; b < TABLE_SIZE; b++)
    if (D[b] != NULL)
    {
        printf("Bucket %d:\n", b);
        traversebucket(D, b);
    }
}