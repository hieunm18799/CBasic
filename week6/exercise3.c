#include <stdio.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

Element ELE_NULL;

typedef struct
{
    int num;
} Element;

typedef struct node_list
{
    Element data;
    struct node_list *next;
    struct node_list *previous;
} List;

Element search(Element key, List *root)
{
    List *temp;

    temp = root;
    while ((temp != NULL) && (temp->data.num != key.num))
        temp = temp->next;
    if (temp != NULL && temp->data.num == key.num)
    {
        temp->previous->next = temp->next;
        temp->next = root->next;
        root = temp;
        return temp->data;
    }
    else
        return ELE_NULL;
}