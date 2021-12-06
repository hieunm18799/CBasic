typedef int KeyType;

typedef struct Node
{
    KeyType key;
    struct Node *left, *right;
} NodeType;
typedef NodeType *TreeType;

TreeType Search(KeyType x, TreeType Root);

void InsertNode(KeyType x, TreeType *Root);

KeyType DeleteMin(TreeType *Root);

void DeleteNode(KeyType X, TreeType *Root);

void prettyprint(TreeType tree, char *prefix);

void freetree(TreeType tree);

void print2DUtil(TreeType root, int space);