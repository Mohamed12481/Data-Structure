#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void printElement(StackEntry e)
{
    printf("%d\n", e);
}


int main()
{
    queue q;
    stack s;
    createStack(&s); 
    printf("------Stack------\n");
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
    printf("=============Now Stack is Done!=============\n");


    printf("\n\n\n------Queue------\n");
    creatQueue(&q);
    printf("[Internal] Front: %d | Rear: %d | Size: %d\n\n", q.front, q.rear, q.size);

    printf("===  Appending 3 Elements (10, 20, 30) ===\n");
    append(10, &q);
    append(20, &q);
    append(30, &q);
    
    printf("Queue contents: \n");
    traversQueue(&q, printElement);
    printf("\n[Internal] Front: %d | Rear: %d | Size: %d\n\n", q.front, q.rear, q.size);

    printf("===  Serving 2 Elements ===\n");
    QueueEntry temp;
    serve(&temp, &q); 
    printf("Served: %d\n", temp);
    serve(&temp, &q); 
    printf("Served: %d\n", temp);
    
    printf("Queue contents: ");
    traversQueue(&q, printElement);
    printf("\n[Internal] Front: %d | Rear: %d | Size: %d\n\n", q.front, q.rear, q.size);

    printf("===  Forcing the Circular Wrap-around ===\n");
    printf("Appending 3 more elements (40, 50, 60)...\n");
    
    append(40, &q); 
    append(50, &q); 
    append(60, &q); 

    printf("Queue contents: ");
    traversQueue(&q, printElement);
    printf("\n[Internal] Front: %d | Rear: %d | Size: %d\n\n", q.front, q.rear, q.size);

    printf("===  Testing Overflow Protection ===\n");
    if (queueFull(&q)) {
        printf("Queue is FULL! Cannot add more elements.\n");
    } else {
        printf("Queue is not full.\n");
    }

    return 0;
}