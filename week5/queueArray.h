#define MaxLength 10

typedef struct
{
    int key;
} ElementType;

typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} QueueArray;

void MakeNull_Queue(QueueArray *Q);

int Empty_Queue(QueueArray Q);

int Full_Queue(QueueArray Q);

void EnQueue(ElementType X, QueueArray *Q);

ElementType DeQueue(QueueArray *Q);