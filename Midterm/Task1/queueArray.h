#define MaxLength 11

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 256
};

typedef struct
{
    char name[MAX_LEN + 1];
    char phone[MAX_LEN + 1];
    char mail[MAX_LEN + 1];
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