#include <stdio.h>
#include <string.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 81
};
void LineReadWrite(FILE *fp)
{
    char buff[MAX_LEN];
    int count = 0;
    while (fgets(buff, MAX_LEN, fp) != NULL)
    {
        count++;
        printf("%d %s", count, buff);
    }
}

int main(int argc, char *argv[])
{
    FILE *fptr;
    int reval = SUCCESS;

    double width, height;
    if (argc != 2)
    {
        printf("Wrong number of arguments!\n");
        return FAIL;
    }

    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    }
    else
    {
        LineReadWrite(fptr);
        fclose(fptr);
    }
    return reval;
}