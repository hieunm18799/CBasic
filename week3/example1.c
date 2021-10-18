#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING 256

typedef struct AddressList
{
    char *name;
    char *phone;
    char *addr;
    char *email;
    node_addr_list *next;
} node_addr_list;

node_addr_list *root = NULL;
node_addr_list *curr = NULL;

node_addr_list *new_node(char *name, char *phone, char *addr, char *email)
{
    node_addr_list *new = (node_addr_list *)malloc(sizeof(node_addr_list));
    new->name = (char *)malloc(sizeof(char) * MAX_STRING);
    new->phone = (char *)malloc(sizeof(char) * MAX_STRING);
    new->addr = (char *)malloc(sizeof(char) * MAX_STRING);
    new->email = (char *)malloc(sizeof(char) * MAX_STRING);
    new->next = NULL;
    return new;
}

int insert_after_curr(node_addr_list *curr, char *name, char *phone, char *addr, char *email)
{
    node_addr_list *node = new_node(name, phone, addr, email);
    node->next = curr->next;
    curr->next = node;
    curr = node;
    if (root == NULL)
        root = node;
    return 1;
}

int delete_first_node(node_addr_list *root)
{
    node_addr_list *tmp = root;
    if (tmp == NULL)
        return 0;
    root = root->next;
    free(tmp);
    return 1;
}

int delete_curr_node(node_addr_list *curr)
{
    node_addr_list *tmp, *node = root;
    if (node == NULL)
        return 0;
    while (node->next != NULL && node->next != curr)
        node = node->next;
    node->next = curr->next;
    tmp = curr;
    free(tmp);
    curr = node;
    return 1;
}

int free_list(node_addr_list *root)
{
    if (root == NULL)
        return 0;
    while (delete_first_node(root) != 0)
        ;
    return 1;
}

int travers_list(node_addr_list *root)
{
    printf("|%-30s|%-10s|%-50s|%-20s|\n", "Name", "Phone", "Address", "Email");
    node_addr_list *tmp;
    tmp = root;
    while (tmp != NULL)
    {
        printf("|%-30s|%-10s|%-50s|%-20s|\n", tmp->name, tmp->phone, tmp->addr, tmp->email);
        tmp = tmp->next;
    }
}

node_addr_list *reverse_list(node_addr_list *root)
{
    node_addr_list *curr, *prev, *tmp;
    tmp = root;
    curr = prev = NULL;
    while (tmp != NULL)
    {
        curr = tmp;
        tmp = tmp->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}