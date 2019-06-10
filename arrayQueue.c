#include "arrayQueue.h"
#include "Malloc.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * The purpose of this file is to create and manipulate an Array Queue.
 * @author: Cameron Cagle
 * @version: 2/27/19
 */
enum constants{initialCapacity = 10, resizeFactor = 2};

typedef struct ArrayQueue ArrayQueue;

struct ArrayQueue{
    /* what does it mean to be dynamically allocated? */
    int* data;

    /* represents the current capacity of the data array. */
    int capacity;    
   
    /* represents the current number of items in the queue. */
    int size;
}; 

/*
 * This function will add the given int to the end of the given Queue. If the given Queue is full,
 * the function will first resize the queue's array by the resize factor.
 * @param: enqueueObject is the given Queue to be added to.
 *         num is the data to be added to the enqueueObject.
 */
static void arrayQueueEnqueue(Queue* enqueueObject, int num){
    ArrayQueue* arrayQueue = (ArrayQueue*)enqueueObject->privateData;
    if (arrayQueue->size == arrayQueue->capacity){
        arrayQueue->data = realloc(arrayQueue->data, sizeof(int) * 
                                  (arrayQueue->capacity * resizeFactor));
        arrayQueue->capacity = arrayQueue->capacity * resizeFactor;
    }
    arrayQueue->data[arrayQueue->size] = num;
    arrayQueue->size++;
}

/*
 * This function will look a the first element in the given array.
 * @param: peekObject is the given Queue that is being peeked at.
 * @return: the data of the first element in the given array.
 */
static int arrayQueuePeek(Queue* peekObject){
    ArrayQueue* arrayQueue = (ArrayQueue*)peekObject->privateData;
    int peek = arrayQueue->data[0];
    return peek;
}

/*
 * This function will remove the first element in the given array.
 * @param: dequeueObject is the Queue whose first element is being removed.
 */
static void arrayQueueDequeue(Queue* dequeueObject){
    ArrayQueue* arrayQueue = (ArrayQueue*)dequeueObject->privateData;
    int i;
    for (i = 0; i < arrayQueue->size - 1; i++){
        arrayQueue->data[i] = arrayQueue->data[i+1];
    }
    arrayQueue->size--;
}

/*
 * This function will give the find the size of the given array. 
 * @param: sizeObject is the Queue the function is finding the size of.
 * @return: an int of the size of the queue.
 */
static int arrayQueueSize(Queue* sizeObject){
    ArrayQueue* arrayQueue = (ArrayQueue*)sizeObject->privateData;
    return arrayQueue->size;
}   

/*
 * This function will print the information of the given array.
 * @param: printObject is the Queue which is being printed.
 */
static void arrayQueuePrint(Queue* printObject){
    ArrayQueue* arrayQueue = (ArrayQueue*)printObject->privateData;
    int i = 0;
    for (i = 0; i < arrayQueue->size; i++){
        if (i == arrayQueue->size - 1){
            printf("%d]\n", arrayQueue->data[i]);
        }
        else if (i == 0){
            printf("[%d , ", arrayQueue->data[i]);
        }
        else{
            printf("%d , ", arrayQueue->data[i]);
        }
    }
}

/*
 * This function will create a new ArrayQueue.
 * @param: newObject is the queue which is being created.
 */
void newArrayQueue(Queue* newObject){
    ArrayQueue *arrayObject = Malloc(sizeof(ArrayQueue));
    arrayObject->data = Malloc(sizeof(int) * initialCapacity);
    arrayObject->capacity = initialCapacity;
    arrayObject->size = 0;
    
    newObject->privateData = arrayObject;
    newObject->enqueue = arrayQueueEnqueue;
    newObject->peek = arrayQueuePeek;
    newObject->dequeue = arrayQueueDequeue;
    newObject->size = arrayQueueSize;
    newObject->print = arrayQueuePrint;
}

/*
 * This function will delete an ArrayQueue.
 * @param: deleteObject is the queue which is being deleted.
 */
void deleteArrayQueue(Queue* deleteObject){
    ArrayQueue* arrayQueue = deleteObject->privateData;
    deleteObject->privateData = NULL;
    deleteObject->enqueue = NULL;
    deleteObject->peek = NULL;
    deleteObject->dequeue = NULL;
    deleteObject->size = NULL;
    deleteObject->print = NULL;
    free(arrayQueue->data); 
    free(arrayQueue);
}







