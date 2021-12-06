#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct node *link;
struct node
{
    Item item;
    link l, r
};
link NEW(Item item, link l, link r)
{
    link x = malloc(sizeof *x);
    x->item = item;
    x->l = l;
    x->r = r;
    return x;
}
link max(Item a[], int l, int r)
{
    int m = (l + r) / 2;
    Item u, v;
    link x = NEW(a[m], NULL, NULL);
    if (l == r)
        return x;
    x->l = max(a, l, m);
    x->r = max(a, m + 1, r);
    u = x->l->item;
    v = x->r->item;
    if (u > v)
        x->item = u;
    else
        x->item = v;
    return x;
}

int main() {
    int l, r;
    int arr[] = {1, 3, 2, 4, 6, 5, 7, 8, 9, 10};
    link tour;

    l = 0; r = 9;

    tour = max(arr, l, r);
    printf("Largest item: %d\n", tour->item);
    return 0;
}