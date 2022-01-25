#include <stdbool.h>

#define TABLE_SIZE 97

typedef struct KeyType
{
    char name[20];
    char tel[11];
    char email[25];
} KeyType;

typedef KeyType *Position;
typedef Position Dictionary[TABLE_SIZE];


bool cmpKey(KeyType *X, KeyType Y);

void MakeNullSet();

int empty(Dictionary D);

int full(Dictionary D);

void clear(Dictionary D);

int insert(Dictionary D, KeyType X);

void removeKey(Dictionary D, KeyType X);

int search(Dictionary D, KeyType X);

void traversebucket(Dictionary D, int b);

void traverse(Dictionary D);