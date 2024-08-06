# Round Robin Scheduling Algorithm

----

## Overview

The Round Robin (RR) scheduling algorithm is one of the most widely used CPU scheduling algorithms. It operates on a cyclic order, where each process is assigned a fixed time quantum in which it can execute. If a process doesn't complete within its time quantum, it is placed at the end of the ready queue, and the next process in the queue gets the CPU. This ensures that each process gets a fair share of the CPU and no single process monopolizes the CPU.

### Key Characteristics

- **Preemptive**: The algorithm can interrupt a process that has not yet completed its execution and give the CPU to the next process in the queue.
- **Fairness**: All processes are given an equal opportunity to use the CPU, as they are scheduled in a round-robin manner.
- **Time Quantum**: The fixed time slice for which each process is allowed to execute before the CPU is given to the next process.

----

## Approach

### Structure Definition

We define a `struct Process` to hold the details of each process:

```c
struct Process {
    int pid;  // Process ID
    int arrival_time;  // Arrival time
    int burst_time;  // Burst time
    int remaining_time;  // Remaining burst time
    int completion_time;  // Completion time
    int turnaround_time;  // Turnaround time
    int waiting_time;  // Waiting time
};
```

### Time Calculation Functions

1. **findTimes**: Computes the completion time, turnaround time, and waiting time for each process using the Round Robin scheduling algorithm. This involves iterating through processes and managing their remaining burst times based on the time quantum.
2. **displayProcesses**: Displays the details of each process along with their computed times in a tabular format.

### Round Robin Scheduling Algorithm

1. **Input**: Number of processes, arrival time, burst time for each process, and the time quantum for the Round Robin scheduling.
2. **Processing**:
   - Maintain a queue to manage processes that are ready to execute.
   - Iterate through the queue, allowing each process to execute for a time quantum or until it completes if it requires less time.
   - Update the remaining burst time and manage the queue as processes arrive and complete.
3. **Output**: Compute and display the completion time, turnaround time, and waiting time for each process.

---

## Time and Space Complexities

### Time Complexity

1. **Finding Times**: The time complexity for finding the completion, turnaround, and waiting times is \(O(n \times m)\), where \(n\) is the number of processes and \(m\) is the number of time slices needed to complete all processes. Each process can potentially be checked multiple times until its remaining time becomes zero.

### Space Complexity

The space complexity is \(O(n)\), where \(n\) is the number of processes. This is because we are using an array of structures to store process information.

---