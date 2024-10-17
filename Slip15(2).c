/*
Slip No 15
Q.2 
Write the program to simulate preemptive Shortest Job First (SJF) –
scheduling. The arrival time and first CPU-burst of different jobs should be
input to the system. Accept no. of Processes, arrival time and burst time. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time
*/

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
} Process;

void findWaitingTime(Process processes[], int n, int waiting[], int quantum) {
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = processes[i].burst; // Initialize remaining time
    }

    int t = 0; // Current time
    while (1) {
        int done = 1; // Flag to check if all processes are done
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= t && remaining[i] > 0) {
                done = 0; // There is at least one process that is not done
                if (remaining[i] > quantum) {
                    t += quantum; // Process the quantum time
                    remaining[i] -= quantum; // Reduce the remaining time
                } else {
                    t += remaining[i]; // Process the remaining time
                    processes[i].waiting = t - processes[i].arrival - processes[i].burst;
                    remaining[i] = 0; // Process is done
                }
            }
        }
        if (done) break; // All processes are done
    }
}

void findTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }
}

void findavgTime(Process processes[], int n, int quantum) {
    int waiting[MAX_PROCESSES];
    findWaitingTime(processes, n, waiting, quantum);
    findTurnAroundTime(processes, n);

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    float total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst, processes[i].waiting, processes[i].turnaround);
        total_waiting += processes[i].waiting;
        total_turnaround += processes[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].remaining = processes[i].burst; // Initialize remaining time
    }

    findavgTime(processes, n, quantum);

    getch();
}