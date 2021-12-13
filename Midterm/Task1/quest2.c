#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 100,
    MAX_STRING = 256
};

typedef struct phoneaddress_t
{
    char name[20];
    char tel[20];
    char email[20];
} phoneaddress;

typedef struct phoneNode
{
    phoneaddress data;
    struct phoneNode *next;
} NodeType;

typedef NodeType *phone;

void InsertNode(phoneaddress x, phone *Root)
{
    // printf("%s %s %s\n", x.name, x.tel, x.email);
    if ((*Root)->next == NULL)
    {
        (*Root)->data = x;
        (*Root)->next = (NodeType *)malloc(sizeof(NodeType));
        (*Root)->next->next = NULL;
        // printf("%s %s %s\n", Root->data.name, Root->data.tel, Root->data.email);
    }
    else
        InsertNode(x, &(*Root)->next);
}

NodeType *middle(NodeType *start, NodeType *last)
{
    if (start == NULL)
        return NULL;

    NodeType *slow = start;
    NodeType *fast = start->next;

    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // printf("%s %s %s\n", slow->data.name, slow->data.tel, slow->data.email);
    }

    return slow;
}

NodeType *binarySearch(NodeType *head, char *find)
{
    NodeType *start = head;
    NodeType *last = NULL;

    do
    {
        NodeType *mid = middle(start, last);

        // printf("%s %s %s\n", mid->data.name, mid->data.tel, mid->data.email);
        if (mid == NULL)
            return NULL;

        if (strcmp(mid->data.name, find) == 0)
            return mid;
        else if (strcmp(mid->data.name, find) < 0)
            start = mid->next;
        else
            last = mid;

    } while (last == NULL || last != start);

    return NULL;
}

int main(void)
{
    FILE *fp, *fpout;
    NodeType *datas;
    NodeType *result;
    char name[20];

    int n = 10;

    if ((fp = fopen("book_inp.txt", "r")) == NULL)
    {
        printf("Can not open %s.\n", "book_inp.txt");
        return FAIL;
    }

    phoneaddress temp;
    int count = 0;

    datas = (NodeType *)malloc(sizeof(NodeType));
    datas->next = NULL;

    while (count < n)
    {
        fscanf(fp, "%s %s %s", temp.name, temp.tel, temp.email);
        // printf("%s %s %s\n", temp.name, temp.tel, temp.email);
        InsertNode(temp, &datas);
        count++;
    }

    fclose(fp);

    printf("Let me know the name you want to search: ");
    scanf("%100s", name);

    result = binarySearch(datas, name);

    if (result == NULL)
    {
        printf("Not found!\n");
        return FAIL;
    }
    if ((fpout = fopen("result.txt", "w")) == NULL)
    {
        printf("Can create file to write!\n");
        return FAIL;
    }
    else
    {
        printf("Found!\n");
        fprintf(fpout, "%s have the email address %s and telephone number: %s ", result->data.name, result->data.email, result->data.tel);
    }
    fclose(fpout);

    return SUCCESS;
}