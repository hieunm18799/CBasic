typedef int elm_type;
//whatever type of element
typedef struct tree_type
{
    elm_type element;
    struct tree_type *left, *right;
} tree_type;

void MakeNullTree(tree_type *T);

int EmptyTree(tree_type *T);

int IsLeaf(tree_type *n);

tree_type *LeftChild(tree_type *n);
tree_type *RightChild(tree_type *n);

tree_type *InitNode();
tree_type *CreateNode(elm_type NewData);
tree_type *CreateNode2(elm_type v, tree_type *l, tree_type *r);

int NumberOfNode(tree_type *T);

tree_type *AddLeft(tree_type *Tree, elm_type NewData);
tree_type *AddRight(tree_type *Tree, elm_type NewData);

int HeightOfBinaryTree(tree_type *node);
int NumberOfLeaft(tree_type *node);
int NumberOfInternalNodes(tree_type *node);
int NumberOfRightNodes(tree_type *node);

void PrintInorder(tree_type *node);

void freetree(tree_type *tree);