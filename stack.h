
#define MAX_STACK 100

typedef int StackEntry;

typedef struct stack
{
    StackEntry top;
    StackEntry entry[MAX_STACK];
} stack;

void createStack(stack *ps);
int stackFull(stack *ps);
int stackEmpty(stack *ps);
void push(StackEntry item, stack *ps);
void pop(StackEntry *pe, stack *ps);
void stackTop(StackEntry *pe, stack *ps);
void stackTopUserLevel(StackEntry *pe, stack *ps);
int stackSize(stack *ps);
void clearStack(stack *ps);
void traverseStack(stack *ps, void (*pf)(StackEntry));