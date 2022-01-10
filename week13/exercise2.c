#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256
#define STRING_TEST 2000
#define STRING_SEARCH 10

enum
{
    FAIL,
    SUCCESS
};

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int *lastOccurenceFunction(char *str, char *set)
{
    int *res = (int *)malloc(sizeof(int) * MAX_STRING);

    memset(res, -1, MAX_STRING);

    for (int i = 0; i < strlen(str); i++)
        if (res[str[i]] == -1)
            res[str[i]] = 1;
        else
            res[str[i]]++;
    return res;
}

int BoyerMooreMatch(char *T, char *P, char *K)
{
    int *L, i, j, l, n, m;

    n = strlen(T);
    m = strlen(P);
    L = lastOccurenceFunction(P, K);
    i = m;
    j = i;

    do
    {
        if (T[i] == P[j])
            if (j == 0)
                return i;
            else
            {
                i = i - 1;
                j = j - 1;
            }
        else
        {
            l = L[T[i]];
            i = i + m - min(j, 1 + l);
            j = m - 1;
        }
    } while (i < n);

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

    res = BoyerMooreMatch(str, search, set);

    if (res == FAIL)
        printf("String not found!\n");
    else
        printf("String found at %d!\n", res + 1);

    return SUCCESS;
}