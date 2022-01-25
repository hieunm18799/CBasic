#include <stdbool.h>

#define TABLE_SIZE 97

typedef struct
{
    char name[20];
    char tel[11];
    char email[25];
} KeyType;
typedef struct Node
{
    KeyType Key;
    struct Node *Next;
} Node;
typedef Node *Position;
typedef Position Dictionary[TABLE_SIZE];

void MakeNullSet();

int emptybucket(Dictionary D, int b);

int empty(Dictionary D);

void clearbucket(Dictionary D, int b);

void clear(Dictionary D);

bool Member(Dictionary D, KeyType X);

void InsertSet(Dictionary D, KeyType X);

void DeleteSet(Dictionary D, KeyType X);

int Search(Dictionary D, KeyType X);

void traversebucket(Dictionary D, int b);

void traverse(Dictionary D);