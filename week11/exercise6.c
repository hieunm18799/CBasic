#include <stdio.h>

enum
{
    FAIL,
    SUCCESS
};

void recurTriangle(int n, char ch);

int main()
{
    long n;

    printf("Input n: ");
    scanf("%ld", &n);

    recurTriangle(n, '+');

    return SUCCESS;
}

void recurTriangle(int n, char ch)
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
            printf("%c", ch);
        printf("\n");
        recurTriangle(n - 1, ch);
    }
}