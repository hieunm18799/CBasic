#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 256

stackList *stackL = NULL;

int main() {
    char *str;
    
    str = (char*) malloc (sizeof(char) * MAX_STRING);
    printf("Enter a string: ");
    gets(str);
    stackL = init_stack();
    for (int i = 0; i < strlen(str); i++) stackL = push_stack((Eltype)str[i], stackL);

    printf("String's reverse: ");
    Eltype tmp_c;
    for (int i = 0; i < strlen(str); i++){
        stackL = pop_stack(&tmp_c, stackL);
        printf("%c", (char)tmp_c);
    }
    printf("\n");
    return 1;
}