#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
#define MAX_STRING 256
#define ARR_SIZE 10
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

int preceding(char *first, char *second);
int setup_nameList(char *namelist[], char *filename);
void SWAP(char **x, char **y);
void quicksort(char *namelist[], int left, int right);

int main(int argc, char *argv[])
{
    char *nameList[MAX_ARRAY_SIZE];

    if (argc != 2)
    {
        printf("The correct syntax should be: ./exercise3 <filename>\n");
        return FAIL;
    }

    setup_nameList(nameList, argv[1]);

    for (int i = 0; i < ARR_SIZE; i++)
        printf("%s ", nameList[i]);
    printf("\n");

    quicksort(nameList, 0, ARR_SIZE - 1);

    for (int i = 0; i < ARR_SIZE; i++)
        printf("%s ", nameList[i]);
    printf("\n");

    return SUCCESS;
}

int preceding(char *first, char *second)
{
    if (strcmp(first, second) < 0)
        return 1;
    if (strcmp(first, second) > 0)
        return -1;
    return 0;
}

int setup_nameList(char *namelist[], char *filename)
{
    FILE *fin;
    phoneaddress phonearr[MAX_ARRAY_SIZE];

    if ((fin = fopen("book_inp.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.dat");
        return FAIL;
    }
    fread(phonearr, sizeof(phoneaddress), ARR_SIZE, fin);
    fclose(fin);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        namelist[i] = (char *)malloc(sizeof(char) * MAX_STRING);
        strcpy(namelist[i], phonearr[i].name);
    }
}

void SWAP(char **x, char **y)
{
    // printf("ok swap\n");
    char *temp = (char *)malloc(sizeof(char) * MAX_STRING);
    strcpy(temp, *x);
    strcpy(*x, *y);
    strcpy(*y, temp);
    // printf("ok swap\n");
}

void quicksort(char *namelist[], int left, int right)
{
    int i, j;

    char *pivot = (char *)malloc(sizeof(char) * MAX_STRING);
    // printf("ok malloc %d %d\n", left, right);
    if (left < right)
    {
        i = left;
        j = right + 1;
        strcpy(pivot, namelist[left]);
        // printf("ok\n");
        do
        {
            // printf("%d %d\n", left, i);
            do
            {
                i++;
            } while (preceding(namelist[i], pivot) > 0 && i < right);
            // printf("%d\n", i);
            do
                j--;
            while (preceding(namelist[j], pivot) < 0 && j > left);

            if (i < j)
                SWAP(&namelist[i], &namelist[j]);
            // printf("%s %s\n", namelist[i], namelist[j]);
            // printf("%d %d\n", i, j);
        } while (i < j);

        SWAP(&namelist[left], &namelist[j]);
        quicksort(namelist, left, j - 1);
        quicksort(namelist, j + 1, right);
    }
}