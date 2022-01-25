#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BINARY 2
#define FIX_NUM1 8
#define FIX_NUM2 31
#define TABLE_SIZE 97

int hashCode_integerCast(char *str);
int hashCode_componentSum(long num);
int hashCode_polynomialAccumulation(char *str);

void main()
{
    printf("Hash code integer cast: %d\n", hashCode_integerCast("AN"));
    printf("Hash code component sum: %d\n", hashCode_componentSum(123456789));
    printf("Hash code polynomial accumulation: %d\n", hashCode_polynomialAccumulation("abc123@gmail.com"));
}

int hashCode_integerCast(char *str)
{
    int result = 0, mul = 0, tmp;
    size_t len = strlen(str);
    char *binary = malloc(len * 8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator

    // printf("%d\n", strlen(str));
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        char ch = str[i];

        // printf("%c\n", ch);
        for (int j = 0; j < 8; j++)
        {
            // printf("%d %d %d\n", result, j, mul);
            if (ch & (1 << j))
            {
                tmp = pow(BINARY, mul);
                result = (result + tmp) % TABLE_SIZE;
                // strcat(binary, "1");
            }
            mul++;
        }
    }

    return result;
}

int hashCode_componentSum(long num)
{
    int result = 0;
    int tmp = pow(2, FIX_NUM1) - 1;
    // printf("%d\n", tmp);

    while (num != 0)
    {
        result = (result + num & tmp) % TABLE_SIZE;
        num = num >> FIX_NUM1;
        // printf("%d\n", result);
    }
    return result;
}
int hashCode_polynomialAccumulation(char *str)
{
    int result = 0;

    for (int i = strlen(str) - 1; i >= 0; i--)
        result = (FIX_NUM2 * result + (int)str[i]) % TABLE_SIZE;
    return result;
}

char *stringToBinary(char *s)
{
    if (s == NULL)
        return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len * 8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for (size_t i = 0; i < len; ++i)
    {
        char ch = s[i];
        for (int j = 7; j >= 0; --j)
        {
            if (ch & (1 << j))
            {
                strcat(binary, "1");
            }
            else
            {
                strcat(binary, "0");
            }
        }
    }
    return binary;
}