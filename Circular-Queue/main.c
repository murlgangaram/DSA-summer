#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

void enqueue(CircularQueue *q, int value);
void dequeue(CircularQueue *q);
void front(CircularQueue *q);
void rear(CircularQueue *q);
void display(CircularQueue *q);

int main() {
    CircularQueue q;
    q.front = -1;
    q.rear = -1;

    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);

    front(&q);
    rear(&q);

    return 0;
}

void enqueue(CircularQueue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
    }
}

void dequeue(CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
    } 
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
}

void front(CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", q->data[q->front]);
    }
}

void rear(CircularQueue *q) {
    if (q->rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Rear element: %d\n", q->data[q->rear]);
    }
}

void display(CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        do {
            printf("%d ", q->data[i]);
            i = (i + 1) % MAX;
        } while (i != (q->rear + 1) % MAX);
        printf("\n");
    }
}
