#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *s;
static int N;
void STACKinit(int maxN)
{
    s = malloc(maxN * sizeof(char));
    N = 0;
}
int STACKempty()
{
    return N == 0;
}
void STACKpush(char item)
{
    s[N++] = item;
}
char STACKpop()
{
    return s[--N];
}

int main(int argc, char *argv[])
{
    char *a = argv[1];
    int i, N = strlen(a);
    STACKinit(N);
    for (i = 0; i < N; i++)
    {
        if (a[i] == ')')
            printf("%c ", STACKpop());
        if ((a[i] == '+') || (a[i] == '*'))
            STACKpush(a[i]);
        if ((a[i] >= '0') && (a[i] <= '9'))
            printf("%c ", a[i]);
    }
    while (!STACKempty()) printf("%c ", STACKpop());
    printf("\n");
    return 1;
}