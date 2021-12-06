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

int insertionSort(phoneaddress phonearr[], int n)
{
    int i, j, count = 0;
    phoneaddress temp;

    for (i = 1; i < n; i++)
    {
        temp = phonearr[i];
        j = i - 1;
        while (strcmp(temp.name, phonearr[j].name) < 0 && (j >= 0))
        {
            count++;
            phonearr[j + 1] = phonearr[j];
            j = j - 1;
        }
        phonearr[j + 1] = temp;
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

    count = insertionSort(phonearr, n);

    printf("Sorted elements have %d comparisons!\n", count);
    printf("Order of Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%s ", phonearr[i].name);
    printf("\n");

    return 0;
}