#define MAX_STACK 100

typedef int StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAX_STACK];
} stack;

void createStack(stack *ps);
int stackFull(stack *ps);
int stackEmpty(stack *ps);
void push(StackEntry item, stack *ps);
void pop(StackEntry *pe, stack *ps);
void stackTop(StackEntry *pe, stack *ps);
int stackSize(stack *ps);
void clearStack(stack *ps);
void traverseStack(stack *ps, void (*pf)(StackEntry));

int main()
{
    stack s;
    createStack(&s);
    return 0;
}

void createStack(stack *ps)
{
    ps->top = 0;
}

int stackFull(stack *ps)
{
    return ps->top == MAX_STACK;
}

int stackEmpty(stack *ps)
{
    return !ps->top;
}

void push(StackEntry item, stack *ps)
{
    if (stackFull(ps))
    {
        return;
    }
    ps->entry[ps->top++] = item;
}

void pop(StackEntry *pe, stack *ps)
{
    if (stackEmpty(ps))
    {
        return;
    }
    *pe = ps->entry[--ps->top];
}

void stackTop(StackEntry *pe, stack *ps)
{
    *pe = ps->entry[(ps->top) - 1];
}

int stackSize(stack *ps)
{
    return ps->top;
}

void clearStack(stack *ps)
{
    ps->top = 0;
}

void traverseStack(stack *ps, void (*pf)(StackEntry))
{
    for (int i = (ps->top); i > 0; i--)
    {
        (*pf)(ps->entry[i - 1]);
    }
    
}