#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 50000

enum
{
    FAIL,
    SUCCESS
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// Print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
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
    int i; // return code
    clock_t t1, t2;

    //random arr
    srand(time(NULL));
    for (i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }

    t1 = clock();

    heapSort(arr1, MAX_ARRAY_SIZE);

    t2 = clock();

    durationinseconds = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Heapsort time's cost: %lf\n", durationinseconds);

    t1 = clock();

    insertionSort(arr2, MAX_ARRAY_SIZE);

    t2 = clock();

    durationinseconds = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Insertion Sort time's cost: %lf\n", durationinseconds);

    return SUCCESS;
}