#include <stdio.h>
#include "FCFS.h"

int main() {
    int num;
    printf("Enter the number of processes: ");
    scanf("%d", &num);

    Queue process;
    initQueue(&process, num);
    inputProcesses(&process, num);

    calculateFCFS(&process);
    display(&process, num);

    float avgTurnaroundTime, avgWaitingTime;
    calculateAverages(&process, &avgTurnaroundTime, &avgWaitingTime);

    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}

