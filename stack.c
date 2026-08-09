#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


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
    if (stackEmpty(ps))
    {
        return;
    }
    
    *pe = ps->entry[(ps->top) - 1];
}

void stackTopUserLevel(StackEntry *pe, stack *ps)
{
    if (stackEmpty(ps))
    {
        return;
    }

    pop(pe, ps);
    push(*pe, ps);
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