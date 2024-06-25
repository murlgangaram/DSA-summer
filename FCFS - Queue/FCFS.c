#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void initQueue(Queue *q, int capacity) {
    q->p = (Process *)malloc(capacity * sizeof(Process));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->size = 0;
}

void enqueue(Queue *q, Process p) {
    if (q->size == q->capacity) {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->p[q->rear] = p;
    q->size++;
}

Process dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    Process d = q->p[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return d;
}

int isEmpty(Queue *q) {
    return (q->size == 0);
}

void inputProcesses(Queue *q, int n) {
    for (int i = 0; i < n; i++) {
        Process p;
        p.process = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p.arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p.burstTime);
        enqueue(q, p);
    }
}

void calculateFCFS(Queue *q) {
    int currentTime = 0;
    for (int i = 0; i < q->capacity; i++) {
        Process *currentProcess = &q->p[i];
        if (currentProcess->arrivalTime > currentTime) {
            currentTime = currentProcess->arrivalTime;
        }
        currentProcess->completionTime = currentTime + currentProcess->burstTime;
        currentTime += currentProcess->burstTime;
        currentProcess->turnaroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
        currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;
    }
}

void calculateAverages(Queue *q, float *avgTurnaroundTime, float *avgWaitingTime) {
    int n = q->capacity;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        Process currentProcess = q->p[i];
        totalTurnaroundTime += currentProcess.turnaroundTime;
        totalWaitingTime += currentProcess.waitingTime;
    }
    *avgTurnaroundTime = (float)totalTurnaroundTime / n;
    *avgWaitingTime = (float)totalWaitingTime / n;
}

void display(Queue *q, int n) {
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        Process currentProcess = q->p[i];
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               currentProcess.process,
               currentProcess.arrivalTime,
               currentProcess.burstTime,
               currentProcess.completionTime,
               currentProcess.turnaroundTime,
               currentProcess.waitingTime);
    }
}

