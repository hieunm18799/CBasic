#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

typedef struct
{
    char name[MAX_LEN + 1];
    char phone[MAX_LEN + 1];
    char mail[MAX_LEN + 1];
} Eltype;

typedef struct stackNode
{
    Eltype data;
    struct stackNode *link;
} stackList;

stackList *init_stack()
{
    stackList *res;
    res = (stackList *)malloc(sizeof(stackList));
    if (res == NULL)
    {
        printf("No Memory available error!\n");
        exit(0);
    }
    res->link = NULL;
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

void copy_file(FILE *fin, FILE *fout);

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;

    if (argc != 3)
    {
        printf("The correct syntax should be: ./exercise3 <filename1> <filename2>\n");
        reval = FAIL;
        exit(0);
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", fptr1);
        reval = FAIL;
        exit(0);
    }
    else if ((fptr2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open %s.\n", fptr2);
        reval = FAIL;
        exit(0);
    }
    else
    {
        copy_file(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}

void copy_file(FILE *fin, FILE *fout)
{
    stackList *stackBookFile;
    Eltype tmp;
    
    stackBookFile = NULL;
    while (!feof(fin))
    {
        fscanf(fin, "%s %s %s", tmp.name, tmp.phone, tmp.mail);

        printf("%s %s %s\n", tmp.name, tmp.phone, tmp.mail);
        stackBookFile = push_stack(tmp, stackBookFile);
    }

    while (stackBookFile != NULL) {
        stackBookFile = pop_stack(&tmp, stackBookFile);
        fprintf(fout, "%s %s %s\n", tmp.name, tmp.phone, tmp.mail);
    }
}