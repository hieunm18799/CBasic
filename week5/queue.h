typedef int ElementType;
typedef struct Node
{
    ElementType Element;
    struct Node *Next; //pointer to next element
};
typedef struct Node *Position;
typedef struct
{
    Position Front, Rear;
} Queue;

void MakeNullQueue(Queue *Q);

int EmptyQueue(Queue Q);

void EnQueue(ElementType X, Queue *Q);

void DeQueue(Queue *Q);