#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hashAddressBook.h"
#include "hashFunc.h"

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
    {
        result = (FIX_NUM2 * result + (int)str[i]) % TABLE_SIZE;
    }

    return result;
}

int hash(void *x)
{
    char *endptr;

    strtol((char *)x, &endptr, MAX_STRING);
    if (*endptr != '\0' || endptr == x)
        return hashCode_polynomialAccumulation((char *)x);
    return hashCode_componentSum((long)x);
}