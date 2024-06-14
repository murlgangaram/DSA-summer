#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void enqueue(Queue *Q, int data) {
    NodePtr temp = malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;
        if (Q->rear == NULL) {
            Q->front = temp;
        } else {
            Q->rear->next = temp;
        }
        Q->rear = temp;
    }
}

void dequeue(Queue *Q) {
    if (Q->front != NULL) {
        NodePtr temp = Q->front;
        Q->front = Q->front->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
    }
}

int front(Queue Q) {
    return (Q.front != NULL) ? Q.front->data : -1;
}

int rear(Queue Q) {
    return (Q.rear != NULL) ? Q.rear->data : -1;
}

bool isEmpty(Queue Q) {
    return Q.rear == NULL;
}

void display(Queue Q) {
    NodePtr current = Q.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}



