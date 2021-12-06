#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char mail[25];
} phoneaddress;

void convertTxtToDat(FILE *fin, FILE *fout);

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
    else if ((fptr2 = fopen(argv[2], "wb")) == NULL)
    {
        printf("Cannot open %s.\n", fptr2);
        reval = FAIL;
        exit(0);
    }
    else
    {
        convertTxtToDat(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}

void convertTxtToDat(FILE *fin, FILE *fout)
{
    phoneaddress tmp;

    while (!feof(fin))
    {
        fscanf(fin, "%s %s %s", tmp.name, tmp.tel, tmp.mail);

        printf("%s %s %s\n", tmp.name, tmp.tel, tmp.mail);
        
        fwrite(&tmp, sizeof(phoneaddress), 1, fout);
    }
    // fprintf(fout, "%s %s %s\n", tmp.name, tmp.tel, tmp.mail);
}