#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

typedef struct node_addr_list
{
    char *name;
    char *phone;
    char *email;
} AddressList;

void read_file(FILE *fin, AddressList *addlist);

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    AddressList addlist[100];
    char tmp[256];
    int reval = SUCCESS;

    if (argc != 2)
    {
        printf("The correct syntax should be: ./exercise3 <filename>\n");
        reval = FAIL;
        exit(0);
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", fptr1);
        reval = FAIL;
        exit(0);
    }
    else
    {
        read_file(fptr1, addlist);
        fclose(fptr1);
    }

    printf("The name you want to find: ");
    scanf("%100s", tmp);

    for (int i = 0; i < 10; i++) {
        if (strcmp(tmp, addlist[i].name) == 0) 
        {
            printf("The result is in %d!\n", i + 1);

            AddressList addtmp;
            addtmp = addlist[0];
            addlist[0] = addlist[i];
            addlist[i] = addtmp;
        }
    }

    return reval;
}

void read_file(FILE *fin, AddressList *addlist)
{    
    while (!feof(fin))
    {
        addlist->name = (char*)malloc(sizeof(char)*256);
        addlist->phone = (char*)malloc(sizeof(char)*256);
        addlist->email = (char*)malloc(sizeof(char)*256);

        fscanf(fin, "%s %s %s", addlist->name, addlist->phone, addlist->email);

        printf("%s %s %s\n", addlist->name, addlist->phone, addlist->email);
        addlist++;
    }
}