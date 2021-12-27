#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 200000

enum
{
    FAIL,
    SUCCESS
};

void SWAP(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int phonearr[], int left, int right)
{
    int i, j;
    int pivot;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = phonearr[left];
        do
        {
            do
                i++;
            while (phonearr[i] < pivot);

            do
                j--;
            while (phonearr[j] > pivot);

            if (i < j)
                SWAP(&phonearr[i], &phonearr[j]);
        } while (i < j);

        SWAP(&phonearr[left], &phonearr[j]);
        quicksort(phonearr, left, j - 1);
        quicksort(phonearr, j + 1, right);
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, count = 0;
    int temp;

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (temp < arr[j] && (j >= 0))
        {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main(void)
{
    int arr1[MAX_ARRAY_SIZE], arr2[MAX_ARRAY_SIZE];
    double durationinseconds;
    long n, i; // return code
    clock_t t1, t2;

    printf("Input n (Max = %d): ", MAX_ARRAY_SIZE);
    scanf("%ld", &n);

    //random arr
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }

    t1 = clock();

    quicksort(arr1, 0, n - 1);

    t2 = clock();

    durationinseconds = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Quicksort time's cost: %lf\n", durationinseconds);

    t1 = clock();

    insertionSort(arr2, n);

    t2 = clock();

    durationinseconds = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Insertion Sort time's cost: %lf\n", durationinseconds);

    return SUCCESS;
}