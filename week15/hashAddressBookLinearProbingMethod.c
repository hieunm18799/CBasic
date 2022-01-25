#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashAddressBookLinearProbingMethod.h"
#include "hashFunc.h"

bool cmpKey(KeyType *X, KeyType Y)
{
    if (strcmp(X->email, Y.email) == 0 && strcmp(X->name, Y.name) == 0 && strcmp(X->tel, Y.tel) == 0)
        return true;
    return false;
}

void MakeNullSet(Dictionary D)
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
        D[i] = NULL;
}

int empty(Dictionary D)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (D[i] != NULL)
            return 0;
    return 1;
}

int full(Dictionary D)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (D[i] == NULL)
            return 0;
    return 1;
}

void clear(Dictionary D)
{
    int b;
    for (b = 0; b < TABLE_SIZE; b++)
        D[b] = NULL;
}

int insert(Dictionary D, KeyType X)
{
    int i;
    if (full(D))
    {
        printf("Hash table is full. Can not insert the key %s\n", X.email);
        return -1;
    }
    i = hash(X.email);
    while (D[i] != NULL)
    {
        // Rehash
        i++;
        if (i > TABLE_SIZE)
            i = i - TABLE_SIZE;
    }
    D[i] = (KeyType *)malloc(sizeof(KeyType));
    *D[i] = X;
    printf("%s\n", D[i]->email);
    return i;
}

void removeKey(Dictionary D, KeyType X)
{
    int j, i, r, a, cont = 1;

    i = hash(X.email);
    do
    {
        D[i] = NULL;
        j = i;
        do
        {
            i = i + 1;
            if (i >= TABLE_SIZE)
                i = i - TABLE_SIZE;
            if (D[i] == NULL)
                cont = 0;
            else
            {
                r = hash(D[i]->email);
                a = (j < r && r <= i) || (r <= i && i < j) || (i < j && j < r);
            }
        } while (cont && a);
        if (cont)
            D[j] = D[i];
    } while (cont);
}

int search(Dictionary D, KeyType X)
{
    int i;
    i = hash(X.email);
    while (!cmpKey(D[i], X) && D[i] != NULL)
    {
        // rehash :fi(key)=f(key)+1) % M
        i = i + 1;
        if (i >= TABLE_SIZE)
            i = i - TABLE_SIZE;
    }
    if (cmpKey(D[i], X)) // found
        return i;
    else // not found
        return -1;
}

void traversebucket(Dictionary D, int b)
{
    Position p;
    p = D[b];

    printf("->%s-%s-%s\n", p->name, p->email, p->tel);
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