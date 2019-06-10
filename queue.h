#ifndef QUEUE_H
#define QUEUE_H
/*
 * @author: Cameron Cagle
 * @version: 2/27/19
 */
typedef struct Queue Queue;
/*
 * This creates a struct of a Queue which holds pointers to functions that manipulate the queue.
 */
struct Queue{
    
    /* 
     * A variable that will referenece the data associated with a concrete Queue implementation.
     */
    void* privateData;   
    
    /*
     * Pointer to an enqueue function.
     */
    void (*enqueue)(Queue*, int);     
    
    /*
     * Pointer to a function peek.
     */
    int (*peek)(Queue*);
    
    /*
     * Pointer to a function dequeued.
     */
    void (*dequeue)(Queue*);

    /*
     * Pointer to a function size.
     */
    int (*size)(Queue*);

    /*
     * Pointer to a function print.
     */
    void (*print)(Queue*); 
}; 
#endif

