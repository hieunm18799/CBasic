#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 100,
    NotFound = -1
};

// the phone book structure
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int BinarySearch(phoneaddress A[], char name[], int N);
void read_file(FILE *fin, phoneaddress *addlist);

int main(void)
{
    FILE *fp, *fpout;
    phoneaddress phonearr[MAX_ELEMENT];
    int i, irc; // return code
    char name[20];
    int reval = SUCCESS;
    int n = 10;

    if ((fp = fopen("book_inp.txt", "r")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.txt");
        reval = FAIL;
    }
    read_file(fp, phonearr);
    fclose(fp);

    if (irc < 0)
    {
        printf(" Can not read from file!");
        return -1;
    }

    printf("Let me know the name you want to search: ");
    scanf("%100s", name);
    irc = BinarySearch(phonearr, name, n);
    if (irc < 0)
    {
        printf("Not found!");
        return -1;
    }
    // write result to outputfile
    if ((fpout = fopen("result.txt", "w")) == NULL)
    {
        printf("Can create file to write.\n");
        reval = FAIL;
    }
    else
    {
        printf("Found!");
        // printf("ok\n");
        fprintf(fpout, "%s have the email address %s and telephone number: %s ", phonearr[irc].name, phonearr[irc].email, phonearr[irc].tel);
        // printf("ok\n");
    }
    fclose(fpout);
    return reval;
}

void read_file(FILE *fin, phoneaddress *addlist)
{
    while (!feof(fin))
    {
        fscanf(fin, "%s %s %s", addlist->name, addlist->tel, addlist->email);
        addlist++;
    }
}

int BinarySearch(phoneaddress A[], char name[], int N)
{
    int Low, Mid, High;
    Low = 0;
    High = N - 1;
    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if (strcmp(A[Mid].name, name) < 0)
            Low = Mid + 1;
        else if (strcmp(A[Mid].name, name) > 0)
            High = Mid - 1;
        else
            return Mid; /* Found */
    }
    return NotFound; /* NotFound is defined as -1 */
}