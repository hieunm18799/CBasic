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

int BruteForceMatch(char *str, char *search)
{
    int i, j, n, m;

    n = strlen(str);
    m = strlen(search);

    for (i = 0; i < n - m + 1; i++)
    {
        j = 0;

        while (j < m && str[i + j] == search[j])
            j++;
        if (j == m)
            return i;
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

    res = BruteForceMatch(str, search);

    if (res == FAIL)
        printf("String not found!\n");
    else
        printf("String found at %d!\n", res + 1);

    return SUCCESS;
}