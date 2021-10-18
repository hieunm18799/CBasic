#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING 256

typedef struct Student_t
{
    char *id;
    char *name;
    int grade;
    struct Student_t *next;
} Student;

Student *add_student(Student *root, Student *to_add)
{
    Student *curr_std, *prev_std = NULL;
    if (root == NULL)
        return to_add;
    if (to_add->grade > root->grade)
    {
        to_add->next = root;
        return to_add;
    }
    curr_std = root;
    while (curr_std != NULL && to_add->grade < curr_std->grade)
    {
        prev_std = curr_std;
        curr_std = curr_std->next;
    }
    prev_std->next = to_add;
    to_add->next = curr_std;
    return root;
}

Student *find_student(Student *root, char *id)
{
    Student *to_search = root; /* Start from root of list */
    while (to_search != NULL)  /* go over all the list */
    {
        if (strcmp(to_search->id, id) == 0) /* same id */
            return to_search;
        to_search = to_search->next;
    }
    /* If we're here, we didn't find */
    return NULL;
}

Student *find_student(Student *root, char *id)
{
    Student *curr_std, *prev_std = NULL;
    if (root == NULL)
        return root;
    curr_std = root;
    if (strcmp(curr_std->id, id) == 0)
    {
        root = root->next;
        free(curr_std);
        return root;
    }
    while (curr_std != NULL && strcmp(curr_std->id, id) != 0)
    {
        prev_std = curr_std;
        curr_std = curr_std->next;
    }
    if (curr_std != NULL)
    {
        prev_std->next = curr_std->next;
        free(curr_std);
    }
    return root;
}