#include <stdio.h>

#define MAX_SIZE 1000 /* maximum size of list plus one */

enum
{
    TRUE,
    FALSE,
};

typedef struct
{
    int key;
    /* other fields */
} element;

element list[MAX_SIZE];

int binsearch(element list[], int searchnum, int n)
{
    /* search list [0], ..., list[n-1]*/
    int left = 0, right = n - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle].key, searchnum))
        {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
        }
    }
    return -1;
}

void verify1(element list1[], element list2[], int n, int m)
/* compare two unordered lists list1 and list2 */
{
    int i, j;
    int marked[MAX_SIZE];
    for (i = 0; i < m; i++)
        marked[i] = FALSE;
    for (i = 0; i < n; i++)
        if ((j = seqsearch(list2, m, list1[i].key)) < 0)
            printf("% d is not in list 2\n ", list1[i].key);
        else
            /* check each of the other fields from list1[i] and list2[j], and
print out any discrepancies */
            marked[j] = TRUE;
    for (i = 0; i < m; i++)
        if (!marked[i])
            printf("% d is not in list1\n", list2[i].key);
}
void verify2(element list1[], element list2[], int n, int m)
/* Same task as verify1, but list1 and list2 are sorted */
{
    int i, j;
    sort(list1, n);
    sort(list2, m);
    i = j = 0;
    while (i < n && j < m)
        if (list1[i].key < list2[j].key)
        {
            printf("% d is not in list 2 \n", list1[i].key);
            i++;
        }
        else if (list1[i].key == list2[j].key)
        {
            /* compare list1[i] and list2[j] on each of the other field and report any discrepancies */
            i++;
            j++;
        }
        else
        {
            printf("% d is not in list 1\n", list2[j].key);
            j++;
        }
    for (; i < n; i++)
        printf("% d is not in list 2\n", list1[i].key);
    for (; j < m; j++)
        printf("% d is not in list 1\n", list2[j].key);
}