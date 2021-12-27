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

void SWAP(phoneaddress *x, phoneaddress *y)
{
    phoneaddress temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(phoneaddress phonearr[], int left, int right)
{
    int i, j;
    phoneaddress pivot;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = phonearr[left];
        do
        {
            do
                i++;
            while (strcmp(phonearr[i].name, pivot.name) < 0);

            do
                j--;
            while (strcmp(phonearr[j].name, pivot.name) > 0);

            if (i < j)
                SWAP(&phonearr[i], &phonearr[j]);
        } while (i < j);

        SWAP(&phonearr[left], &phonearr[j]);
        quicksort(phonearr, left, j - 1);
        quicksort(phonearr, j + 1, right);
    }
}

int main(void)
{
    FILE *fin, *fout;
    phoneaddress phonearr[MAX_ARRAY_SIZE], temp;
    int i, j, n, irc; // return code
    int reval = SUCCESS;

    n = 10;

    //read from this file to array again
    if ((fin = fopen("book_inp.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fin);
    fclose(fin);

    quicksort(phonearr, 0, n - 1);

    if ((fout = fopen("book_inp.out", "w")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.out");
        reval = FAIL;
    }
    for (i = 0; i < n; i++) fprintf(fout, "%s %s %s\n", phonearr[i].name, phonearr[i].tel, phonearr[i].email);
    fclose(fout);

    return 0;
}