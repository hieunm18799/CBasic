#include <stdio.h>
#include <stdlib.h>
#include "hashAddressBook.h"

#define DATA_LENGTH 10

enum
{
    FAIL,
    SUCCESS
};

Dictionary D;

int main(void)
{
    FILE *fin, *fout;
    KeyType tmpArr[DATA_LENGTH];
    int irc; // return code

    MakeNullSet(D);
    // read from this file to array again
    if ((fin = fopen("book_inp.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.dat");
        return FAIL;
    }
    irc = fread(tmpArr, sizeof(KeyType), DATA_LENGTH, fin);
    fclose(fin);

    printf("Data\n");
    for (int i = 0; i < DATA_LENGTH; i++)
    {
        InsertSet(D, tmpArr[i]);
        printf("%s %s %s\n", tmpArr[i].name, tmpArr[i].email, tmpArr[i].tel);
    }

    traverse(D);

    return SUCCESS;
}