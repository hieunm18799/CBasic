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

void merge(phoneaddress arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    phoneaddress L[n1], R[n2];
    // Copy data to temp array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].name, R[j].name) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(phoneaddress arr[], int l, int r)
{
    if (l < r)
    {
        // Finding mid element
        int m = l + (r - l) / 2;
        // Recursively sorting both the halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the array
        merge(arr, l, m, r);
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

    mergeSort(phonearr, 0, n - 1);

    if ((fout = fopen("book_inp.out", "w")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.out");
        reval = FAIL;
    }
    for (i = 0; i < n; i++)
        fprintf(fout, "%s %s %s\n", phonearr[i].name, phonearr[i].tel, phonearr[i].email);
    fclose(fout);

    return 0;
}