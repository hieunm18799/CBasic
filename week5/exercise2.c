#include <stdio.h>
#include "queueArray.h"

QueueArray q;

int main() {
    int n, tmp;

    scanf("%d", &n);
    ElementType eleTmp;

    MakeNull_Queue(&q);
    q.Rear = 0;
    q.Front = 0;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &tmp);
        eleTmp.key = tmp;
        EnQueue(eleTmp, &q);
    }
    return 0;
}