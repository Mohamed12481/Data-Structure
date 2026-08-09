#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void printElement(StackEntry e)
{
    printf("%d\n", e);
}


int main()
{
    stack s;
    createStack(&s); 

    printf("--- Pushing Elements ---\n");
    push(10, &s);
    push(20, &s);
    push(30, &s);
    push(40, &s);
    push(50, &s);
    printf("Elements (10, 20, 30, 40, 50) have been pushed.\n");
    printf("Current Size: %d\n", stackSize(&s));

    
    printf("\n--- Traversing Stack ---\n");
    traverseStack(&s, printElement);

    printf("\n--- Checking Top ---\n");
    StackEntry topVal;
    stackTop(&topVal, &s);
    printf("Top Element is: %d\n", topVal);

    printf("\n--- Popping Element ---\n");
    StackEntry poppedVal;
    pop(&poppedVal, &s);
    printf("Popped Element: %d\n", poppedVal);
    printf("Size after Pop: %d\n", stackSize(&s));

    printf("\n--- Clearing Stack ---\n");
    clearStack(&s);
    
    if (stackEmpty(&s))
    {
        printf("Stack is now completely empty. Size: %d\n", stackSize(&s));
    }

    return 0;
}