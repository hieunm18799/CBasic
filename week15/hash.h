#define ARRAY_SIZE 100

typedef int KeyType;
typedef struct Node
{
    KeyType Key;
    struct Node *Next;
} Node;
typedef Node *Position;
typedef Position Dictionary[ARRAY_SIZE];

void MakeNullSet();

int emptybucket(Dictionary D, int b);

int empty(Dictionary D);

void clearbucket(Dictionary D, int b);

void clear(Dictionary D);

void InsertSet(Dictionary D, KeyType X);

void DeleteSet(Dictionary D, KeyType X);

int Search(Dictionary D, KeyType X);

void traversebucket(Dictionary D, int b);

void traverse(Dictionary D);