#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stackList *init_stack()
{
    stackList *res;
    res = (stackList *)malloc(sizeof(stackList));
    if (res == NULL) {
        printf("No Memory available error!\n");
        exit(0);
    }
    res->link = NULL;
    res->data = 0;
    return res;
}

int ifempty_stack(stackList *stack)
{
    if (stack == NULL)
        return 1;
    return 0;
}

stackList *push_stack(Eltype el, stackList *stack)
{
    stackList *pushEl;
    pushEl = init_stack();
    pushEl->data = el;
    pushEl->link = stack;
    stack = pushEl;
    return stack;
}

stackList *pop_stack(Eltype *el, stackList *stack)
{
    if (ifempty_stack(stack))
        printf("Stack is empty!\n");
    else
    {
        stackList *tmp;
        *el = stack->data;
        tmp = stack;
        stack = stack->link;
        free(tmp);
        return stack;
    }
}