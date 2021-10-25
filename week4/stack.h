typedef int Eltype;
typedef struct stackNode
{
    Eltype data;
    struct stackNode *link;
} stackList;

stackList *init_stack();
int ifempty_stack(stackList *stack);
stackList *push_stack(Eltype el, stackList *stack);
stackList *pop_stack(Eltype *el, stackList *stack);