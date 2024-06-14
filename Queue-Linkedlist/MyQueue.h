#ifndef MyQueue_h
#define MyQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
} Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, int data);
void dequeue(Queue *Q);
int front(Queue Q);
int rear(Queue Q);
bool isEmpty(Queue Q); 
void display(Queue Q);


#endif
