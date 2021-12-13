#include <stdio.h>
#include <string.h>
#include "queueArray.h"

QueueArray q;

int main() {
    int n;
    char tmp[MAX_LEN];

    printf("Input the numbers of address: ");
    scanf("%d", &n);
    ElementType eleTmp;

    MakeNull_Queue(&q);
    q.Rear = 0;
    q.Front = 0;
    for (int i = 0; i < n; i++) 
    {
        printf("Input the address %d!\n", i + 1);
        printf("Name: ");
        scanf("%100s", &tmp);
        strcpy(eleTmp.name, tmp);

        printf("Phone: ");
        scanf("%100s", &tmp);
        strcpy(eleTmp.phone, tmp);

        printf("Email: ");
        scanf("%100s", &tmp);
        strcpy(eleTmp.mail, tmp);

        EnQueue(eleTmp, &q);
    }
    return 0;
}