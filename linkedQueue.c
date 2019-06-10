#include "queue.h"
#include "linkedQueue.h"
#include "Malloc.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * The purpose of this file is to create and manipulate a Linked Queue.
 * @author: Cameron Cagle
 * @version: 2/27/19
 */

typedef struct Node Node;
/*
 * This creates a Node struct which holds the data of the node and a pointer to the next node
 * in the linked queue.
 */
struct Node{
    /* represents the integer data the node will hold. */
    int data;

    /* pointer to the next node in the list. */
    Node* nextNode;
}; 

typedef struct LinkedQueue LinkedQueue;
/*
 * This creates a LinkedQueue struct that holds two Node pointers, which point to the head and tail
 * of the linked queue, and the size of the struct.
 */
struct LinkedQueue{
    /* pointer to the first node in the linked list. */
    Node* head;
   
    /* pointer to the last node in the linked list. */ 
    Node* tail;
   
    /* the number of items in the linked list */ 
    int size;
};

/*
 * This function creates a new node.
 * @param: newData is the new data being stored in the node.
 *         nextNode is a pointer to the next node in the linked list.
 * @return: a pointer to a node object.
 */
static Node* newNode(int newData, Node* nextNode){
    Node* createNode = Malloc(sizeof(Node));
    createNode->data = newData;
    createNode->nextNode = nextNode;
    return createNode;
}

/*
 * This delets all dynamically allocated memory associated with the node.
 * @param: deletedNode is the node that is being deleted.
 */
static void deleteNode(Node* deletedNode){
    deletedNode->data = 0;
    deletedNode->nextNode = NULL;
    free(deletedNode); 
}

/*
 * This function will add the given int to the end of the given Queue.
 * @param: enqueueQueue is the queue pointer which is being added to.
 *         num is the data being added to the queue.
 */
static void linkedQueueEnqueue(Queue* enqueueQueue, int num){
    LinkedQueue* linkedQueue = (LinkedQueue*)enqueueQueue->privateData;
    Node* toAdd = newNode(num, NULL);
    if (linkedQueue->size == 0){
        linkedQueue->head = toAdd;
        linkedQueue->tail = toAdd;
        linkedQueue->size++;
    }
    else{
        linkedQueue->tail->nextNode = toAdd;
        linkedQueue->tail = toAdd;
        linkedQueue->size++;
    }
}

/*
 * This function will peek at the first element in given Queue.
 * @param: peekQueue is the Queue which is being peeked at.
 * @return: the first element in the given queue.
 */
static int linkedQueuePeek(Queue* peekQueue){
    LinkedQueue* linkedQueue = (LinkedQueue*)peekQueue->privateData;
    return linkedQueue->head->data;
}

/*
 * This function will remove the first element of from the queue, and free any memory associated 
 * with the node containing that first item.
 * @param: dequeueQueue is queue which is being deleted from.
 */
static void linkedQueueDequeue(Queue* dequeueQueue){
    LinkedQueue* linkedQueue = (LinkedQueue*)dequeueQueue->privateData;
    Node* next = linkedQueue->head->nextNode;
    deleteNode(linkedQueue->head);
    linkedQueue->head = next;  
    linkedQueue->size--;
}

/*
 * This function will check the size of the queue.
 * @param: sizeQueue is the queue whose size is being returned.
 * @return: the size of the given queue.
 */
static int linkedQueueSize(Queue* sizeQueue){
    LinkedQueue* linkedQueue = (LinkedQueue*)sizeQueue->privateData;
    return linkedQueue->size;     
}

/*
 * This function will print out the given queue.
 * @param: printQueue is the queue which is being printed.
 */
static void linkedQueuePrint(Queue* printQueue){
    LinkedQueue* linkedQueue = (LinkedQueue*)printQueue->privateData;
    Node* next = linkedQueue->head->nextNode;
    int i = 0;
    for (i = 0; i < linkedQueue->size; i++){
        if (i == 0){
            printf("[%d , ", linkedQueue->head->data);
        }
        else if (i == linkedQueue->size - 1){
            printf("%d]\n", linkedQueue->tail->data);
        }
        else{
            printf("%d , ", next->data);
            next = next->nextNode;
        }
    }
}

/*
 * This function will dynamically create an appropriately initialized LinkedQueue and store it in
 * the privateData field of the queue. It will also initialize each of the pointers to functions
 * to the corresponding static functions described above.
 * @param: newQueue is the new queue that is being created.
 */
void newLinkedQueue(Queue* newQueue){
    LinkedQueue* linkedQueue = Malloc(sizeof(LinkedQueue));
    linkedQueue->head = NULL;
    linkedQueue->tail = NULL;
    linkedQueue->size = 0;

    newQueue->privateData = linkedQueue;
    newQueue->enqueue = linkedQueueEnqueue;
    newQueue->peek = linkedQueuePeek;
    newQueue->dequeue = linkedQueueDequeue;
    newQueue->size = linkedQueueSize;
    newQueue->print = linkedQueuePrint;
}

/*
 * This function will free any dynamically allocated memory associated with the given Queue and set
 * all pointers to NULL.
 * @param: deletedQueue is the queue which is being deleted.
 */
void deleteLinkedQueue(Queue* deletedQueue){
    LinkedQueue* linkedQueue = (LinkedQueue*)deletedQueue->privateData;
    Node* follower = linkedQueue->head;
    while (follower != NULL){
        linkedQueue->head = linkedQueue->head->nextNode;
        deleteNode(follower);
        follower = linkedQueue->head;
    }
    deletedQueue->privateData = NULL;
    deletedQueue->enqueue = NULL;
    deletedQueue->peek = NULL;
    deletedQueue->dequeue = NULL;
    deletedQueue->size = NULL;
    deletedQueue->print = NULL;
    free(linkedQueue);
}


