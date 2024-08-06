#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int remaining_time; // Remaining burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
};

void findTimes(struct Process proc[], int n, int quantum) {
    int current_time = 0;
    int done = 0;

    while (done < n) {
        done = 0;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    current_time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    current_time += proc[i].remaining_time;
                    proc[i].completion_time = current_time;
                    proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                }
            } else {
                done++;
            }
        }
    }
}

void displayProcesses(struct Process proc[], int n) {
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time, 
               proc[i].completion_time, proc[i].turnaround_time, proc[i].waiting_time);
    }
}

int main() {
    int n, quantum;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].pid = i + 1; // Assign process ID
        proc[i].remaining_time = proc[i].burst_time; // Initialize remaining time
    }

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Find completion, turnaround, and waiting times
    findTimes(proc, n, quantum);

    // Display processes and their times
    displayProcesses(proc, n);

    return 0;
}