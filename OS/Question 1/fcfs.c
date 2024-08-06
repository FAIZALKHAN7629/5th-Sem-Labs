#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;  // Process ID
    int arrival_time;  // Arrival time
    int burst_time;  // Burst time
    int completion_time;  // Completion time
    int turnaround_time;  // Turnaround time
    int waiting_time;  // Waiting time
};

// Function to find the completion, turnaround, and waiting times
void findTimes(struct Process proc[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        // Completion time is the current time plus the burst time of the process
        current_time = current_time + proc[i].burst_time;
        proc[i].completion_time = current_time;

        // Turnaround time is the completion time minus the arrival time
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;

        // Waiting time is the turnaround time minus the burst time
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
    }
}

// Function to display the processes and their calculated times
void displayProcesses(struct Process proc[], int n) {
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time, 
               proc[i].completion_time, proc[i].turnaround_time, proc[i].waiting_time);
    }
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].pid = i + 1;  // Assign process ID
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // Find completion, turnaround, and waiting times
    findTimes(proc, n);

    // Display processes and their times
    displayProcesses(proc, n);

    return 0;
}
