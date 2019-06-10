#include "arrayQueue.h"
#include "linkedQueue.h"
#include "queue.h"
#include <stdio.h>
/*
 * This file is the driver for my program 
 * @author: Cameron Cagle
 * @version: 2/27/19
 */

/*
 * This function tests all the methods of queue. These methods include enqueue, dequeue, size,
 * print, and peek. 
 * @param: queue is a pointer to a queue to test.
 */
static void testQueue(Queue* queue) {
    int i = 0;
    int testCapacity = 42;      /* checks if the resize factor will work */
    for (i = 0; i < testCapacity; i++){ 
        queue->enqueue(queue, i);
    }
    queue->print(queue);
    printf("****RESULTS****\nSize of Queue: %d\n", queue->size(queue));
    printf("Peek at: %d\n\n", queue->peek(queue));
    for (i = 0; i < testCapacity / 2; i++){
        queue->dequeue(queue);
    }
    queue->print(queue);            
    printf("****RESULTS****\nSize of Queue: %d\n", queue->size(queue));
    printf("Peek at: %d\n\n", queue->peek(queue));
    for (i = 0; i < testCapacity / 4; i++){
        queue->enqueue(queue, i);
    }
    queue->print(queue);
    printf("****RESULTS****\nSize of Queue: %d\n", queue->size(queue));
    printf("Peek at: %d\n\n", queue->peek(queue));
    
}
/*
 * This function makes an array queue and linked queue and tests them both. Once they have been 
 * tested they are deleted and all dynamically allocated memory should be free.
 */
int main(void) {
    Queue queue;              /* A generic Queue */
    
    printf("\n*************ARRAY QUEUE TEST*************\n");
    newArrayQueue(&queue);    /* Make the Queue an ArrayQueue. */
    testQueue(&queue);        /* Test its implementation. */
    deleteArrayQueue(&queue); /* Delete the ArrayQueue. */

    
    printf("\n*************LINKED QUEUE TEST*************\n");
    newLinkedQueue(&queue);   /* Make the Queue a LinkedQueue. */
    testQueue(&queue);        /* Test its implementation. */
    deleteLinkedQueue(&queue); /* Delete the LinkedQueue. */

    return 0;
}


