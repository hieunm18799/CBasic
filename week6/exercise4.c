#include <stdio.h>

#define NotFound (-1)
#define MAX_LENGTH 100

typedef int ElementType;

int BinarySearch(ElementType A[], ElementType X, int Lo, int Hi);

int comp_count = 0;

int main()
{
    int A[MAX_LENGTH];
    int find;

    for (int i = 0; i < MAX_LENGTH; i++) A[i] = i + 1;

    printf("Print finding number: ");
    scanf("%d", &find);

    printf("The result is %d", BinarySearch(A, find, 0, MAX_LENGTH));
    printf(" after %d comparisons!\n", comp_count);
    
    return 0;
}

int BinarySearch(ElementType A[], ElementType X, int Lo, int Hi)
{
    int Mid;

    comp_count++;
    if (Lo > Hi)
        return NotFound;

    Mid = (Lo + Hi) / 2;
    if (A[Mid] < X)
        return BinarySearch(A, X, Mid + 1, Hi);
    else if (A[Mid] > X)
        return BinarySearch(A, X, Lo, Mid - 1);
    else
        return Mid; /* Found */
}