#include <stdio.h>

#define STRING_LEN 100

void replace_char(char *str, char c1, char c2)
{
    if (str == NULL)
        return;
    while (*str != '\0')
    {
        if (*str == c1)
            *str = c2;
        ++str;
    }
}

int main(void)
{
    char str[STRING_LEN + 1];
    char replace_what, replace_with, tmp;
    printf("Please enter a string (no spaces)\n");
    scanf("%100s", str);
    printf("Letter to replace: ");
    scanf(" %c", &replace_what);
    do
    {
        tmp = getchar();
    } while (tmp != '\n');
    printf("Letter to replace with: ");
    scanf(" %c", &replace_with);
    replace_char(str, replace_what, replace_with);
    printf("The result: %s\n", str);
    return 0;
}