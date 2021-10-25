#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 256

stackList *stackFirstNum = NULL;
stackList *stackSecondNum = NULL;
stackList *stackSumNum = NULL;

int check_number_of_string(char *str);

int main()
{
    char *str1, *str2;

    str1 = (char *)malloc(sizeof(char) * MAX_STRING);
    str2 = (char *)malloc(sizeof(char) * MAX_STRING);

    printf("Adding very large numbers!\n");
    printf("Enter first number: ");
    gets(str1);
    printf("Enter second number: ");
    gets(str2);

    if (check_number_of_string(str1) && check_number_of_string(str2))
    {
        Eltype num1, num2;
        int add_num, flag = 0;
        stackFirstNum = init_stack();
        for (int i = 0; i < strlen(str1); i++)
            stackFirstNum = push_stack((Eltype)(str1[i] - '0'), stackFirstNum);

        stackSecondNum = init_stack();
        for (int i = 0; i < strlen(str2); i++)
            stackSecondNum = push_stack((Eltype)(str2[i] - '0'), stackSecondNum);

        int length = 0;
        if (strlen(str1) > strlen(str2))
            length = strlen(str2);
        else
            length = strlen(str1);

        stackSumNum = init_stack();
        for (int i = 0; i < length; i++)
        {
            stackFirstNum = pop_stack(&num1, stackFirstNum);
            stackSecondNum = pop_stack(&num2, stackSecondNum);

            add_num = num1 + num2 + flag;
            flag = 0;
            if (add_num > 9)
            {
                add_num = add_num - 10;
                flag = 1;
            }

            stackSumNum = push_stack(add_num, stackSumNum);
        }

        if (strlen(str1) > strlen(str2))
        {
            for (int i = 0; i < strlen(str1) - length; i++)
            {
                stackFirstNum = pop_stack(&num1, stackFirstNum);

                add_num = num1 + flag;
                flag = 0;
                if (add_num > 9)
                {
                    add_num = add_num - 10;
                    flag = 1;
                }

                stackSumNum = push_stack(add_num, stackSumNum);
            }
        } else {
            for (int i = 0; i < strlen(str2) - length; i++)
            {
                stackSecondNum = pop_stack(&num2, stackSecondNum);

                add_num = num2 + flag;
                flag = 0;
                if (add_num > 9)
                {
                    add_num = add_num - 10;
                    flag = 1;
                }

                stackSumNum = push_stack(add_num, stackSumNum);
            }
        }

        if (strlen(str1) > strlen(str2)) length = strlen(str1);
        else length = strlen(str2);

        if (flag == 1) {
            length++;
            stackSumNum = push_stack(1, stackSumNum);
        }

        Eltype tmp;
        printf("Result: ");
        for (int i = 0; i < length; i++) {
            stackSumNum = pop_stack(&tmp, stackSumNum);
            printf("%d", tmp);
        }
        printf("\n");
    } else printf("Wrong input!\n");

    return 1;
}

int check_number_of_string(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}