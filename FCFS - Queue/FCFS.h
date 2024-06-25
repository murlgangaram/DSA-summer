#ifndef FCFS_H
#define FCFS_H

typedef struct {
    int process;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
} Process;

typedef struct {
    Process *p;
    int front, rear;
    int capacity;
    int size;
} Queue;

void initQueue(Queue *q, int capacity);
void enqueue(Queue *q, Process p);
Process dequeue(Queue *q);
int isEmpty(Queue *q);
void calculateFCFS(Queue *q);
void inputProcesses(Queue *q, int n);
void calculateAverages(Queue *q, float *avgTurnaroundTime, float *avgWaitingTime);
void display(Queue *q, int n);

#endif
