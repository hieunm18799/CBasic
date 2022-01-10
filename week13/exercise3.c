#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256
#define STRING_TEST 2000
#define STRING_SEARCH 10

int counter_comparison = 0;

enum
{
    FAIL,
    SUCCESS
};

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int *failureFunction(char *P)
{
    int i, j, m;
    int *res = (int *)malloc(sizeof(int) * MAX_STRING);

    m = strlen(P);
    res[0] = 0;
    i = 1;
    j = 0;

    while (i < m)
    {
        if (P[i] == P[j])
        {
            res[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = res[j - 1];
        }
        else
        {
            res[i] = 0;
            i++;
        }
    }
    return res;
}

int KMPMatch(char *T, char *P)
{
    int *F, n, m, i, j;

    n = strlen(T);
    m = strlen(P);
    F = failureFunction(P);
    i = 0;
    j = 0;

    while (i < n)
    {
        if (T[i] == P[j])
            if (j == m - 1)
                return i - j;
            else
            {
                i++;
                j++;
            }

        else if (j > 0)
            j = F[j - 1];
        else
            i++;
        counter_comparison++;
    }

    return FAIL;
}

int main(void)
{
    char str[STRING_TEST + 1], set[] = "abcdef", search[STRING_SEARCH];
    int res, ran_res;
    clock_t t;

    strcpy(search, "aadbf");

    // random
    srand(time(NULL));
    for (int i = 0; i < STRING_TEST; i++)
    {
        str[i] = set[rand() % strlen(set)];
    }
    str[STRING_TEST] = '\0';

    printf("The string we have: %s\n", str);
    printf("The string we searching: %s\n", search);

    res = KMPMatch(str, search);

    if (res == FAIL)
        printf("String not found!\n");
    else
        printf("String found at %d!\n", res + 1);

        printf("the number of comparisons: %d\n", counter_comparison);

    return SUCCESS;
}