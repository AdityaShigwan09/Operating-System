/*
Q.2 
Write a C program to simulate Preemptive Priority scheduling. The arrival
time and first CPU-burst and priority for different n number of
processes should be input to the algorithm. Assume the fixed IO
waiting time (2 units). The next CPU-burst should be generated randomly. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<conio.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int waiting;
    int turnaround;
} Process;

void generateRandomBurst(Process *process) {
    // Generate a random burst time (1 to 10) for the next CPU burst
    process->burst = rand() % 10 + 1;
    process->remaining = process->burst; // Set remaining time to new burst time
}

void calculateTimes(Process processes[], int n) {
    int total_waiting = 0, total_turnaround = 0;
    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
        total_waiting += processes[i].waiting;
        total_turnaround += processes[i].turnaround;
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst, processes[i].priority, processes[i].waiting, processes[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

void preemptivePriorityScheduling(Process processes[], int n) {
    int time = 0;
    int completed = 0;
    int gantt[MAX_PROCESSES * 2]; // Gantt chart
    int gantt_index = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = -1;

        // Find the process with the highest priority that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && processes[i].remaining > 0) {
                if (processes[i].priority > highest_priority) {
                    highest_priority = processes[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Execute the process for 1 time unit
            gantt[gantt_index++] = processes[idx].id;
            processes[idx].remaining--;

            // If the process is completed
            if (processes[idx].remaining == 0) {
                processes[idx].waiting = time + 1 - processes[idx].arrival - processes[idx].burst;
                completed++;
            }
        } else {
            gantt[gantt_index++] = -1; // No process is ready to execute
        }
        time++;
    }

    // Print Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_index; i++) {
        if (gantt[i] == -1) {
            printf("Idle ");
        } else {
            printf("P%d ", gantt[i]);
        }
    }
    printf("\n");

    calculateTimes(processes, n);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID
        printf("Enter arrival time, burst time and priority for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
        processes[i].remaining = processes[i].burst; // Initialize remaining time
    }

    preemptivePriorityScheduling(processes, n);

    getch();
}