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

void swap(phoneaddress *xp, phoneaddress *yp)
{
    phoneaddress temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort(phoneaddress arr[], int n)
{
    int i, j, min_idx, count = 0;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(arr[j].name, arr[min_idx].name) < 0)
            {
                count++;
                min_idx = j;
            }

        swap(&arr[min_idx], &arr[i]);
    }
}

int main(void)
{
    FILE *fp;
    phoneaddress phonearr[MAX_ARRAY_SIZE], temp;
    int i, j, n, irc, count; // return code
    int reval = SUCCESS;

    n = 10;

    //read from this file to array again
    if ((fp = fopen("book_inp.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    fclose(fp);

    printf("Book phone's name: ");
    for (i = 0; i < n; i++)
        printf("%s ", phonearr[i].name);
    printf("\n");

    count = selectionSort(phonearr, n);

    printf("Sorted elements have %d comparisons!\n", count);
    printf("Order of Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%s ", phonearr[i].name);
    printf("\n");

    return 0;
}