#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

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

int heapify(phoneaddress list[], int root, int n)
{
    int child, count = 0;
    phoneaddress temp;

    temp = list[root];
    child = 2 * root;
    while (child <= n)
    {
        if (child < n && strcmp(list[child].name, list[child + 1].name) < 0)
        {
            count++;
            child++;
        }
        if (strcmp(list[root].name, list[child].name) > 0)
        {
            count++;
            break;
        }
        else
        {
            count++;
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;

    return count;
}

int heapsort(phoneaddress list[], int n)
{
    int i, j, count = 0;
    phoneaddress temp;
    for (i = n / 2; i > 0; i--)
        count += heapify(list, i, n);
    for (i = n - 1; i > 0; i--)
    {
        swap(&list[1], &list[i + 1]);
        count += heapify(list, 1, i);
    }

    return count;
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

    //0 -> n-1 To 1 -> n
    for (i = n; i >= 1; i--)
        phonearr[i] = phonearr[i-1];
    printf("Book phone's name: ");
    for (i = 1; i <= n; i++)
        printf("%s ", phonearr[i].name);
    printf("\n");

    count = heapsort(phonearr, n);

    printf("Sorted elements have %d comparisons!\n", count);
    printf("Order of Sorted elements: ");
    for (i = 1; i <= n; i++)
        printf("%s ", phonearr[i].name);
    printf("\n");

    return 0;
}