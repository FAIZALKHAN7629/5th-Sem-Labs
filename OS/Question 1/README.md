# FCFS Scheduling Algorithm

----

## Overview

The First-Come, First-Served (FCFS) scheduling algorithm is one of the simplest types of CPU scheduling algorithms. It operates on the principle that processes are executed in the order they arrive in the ready queue. The process that arrives first gets executed first. 

### Key Characteristics

- **Non-Preemptive**: Once a process starts its execution, it runs to completion before the next process starts.
- **Fairness**: Each process gets a chance to execute based on its arrival time, ensuring that no process is starved.
- **Simplicity**: Easy to implement and understand, making it a good choice for educational purposes and simpler systems.

----

## Approach

### Structure Definition

We define a `struct Process` to hold the details of each process:

```c
struct Process {
    int pid;  // Process ID
    int arrival_time;  // Arrival time
    int burst_time;  // Burst time
    int completion_time;  // Completion time
    int turnaround_time;  // Turnaround time
    int waiting_time;  // Waiting time
};
```

### Time Calculation Functions

1. **findTimes**: Computes the completion time, turnaround time, and waiting time for each process based on FCFS scheduling rules.
2. **displayProcesses**: Displays the details of each process along with their computed times in a tabular format.

### FCFS Scheduling Algorithm

1. **Input**: Number of processes, arrival time, and burst time for each process.
2. **Sort**: Processes are sorted based on their arrival time to adhere to FCFS scheduling.
3. **Compute Times**:
   - **Completion Time**: For each process, it is computed as the sum of the burst time and the start time.
   - **Turnaround Time**: The difference between the completion time and arrival time.
   - **Waiting Time**: The difference between turnaround time and burst time.

4. **Display Results**: The results are presented in a tabular format showing Process ID, Arrival Time, Burst Time, Completion Time, Turnaround Time, and Waiting Time.

### Example

Consider the following processes:

- Process 1: Arrival Time = 0, Burst Time = 4
- Process 2: Arrival Time = 1, Burst Time = 3
- Process 3: Arrival Time = 2, Burst Time = 2

The scheduling would be:

1. Process 1 starts at time 0 and completes at time 4.
2. Process 2 starts at time 4 and completes at time 7.
3. Process 3 starts at time 7 and completes at time 9.

The turnaround time and waiting time for each process are computed based on these times.

----

## Time and Space Complexities

### Time Complexity

1. **Sorting the Processes**: The sorting step has a time complexity of \(O(n^2)\) because bubble sort is used for simplicity. Using a more efficient sorting algorithm (e.g., quicksort or mergesort) reduces it to \(O(n \log n)\).
2. **Calculating Times**: The time complexity for calculating completion, turnaround, and waiting times is \(O(n)\).

Overall, the time complexity is \(O(n^2)\) due to the sorting step. If an efficient sorting algorithm is used, it can be reduced to \(O(n \log n)\).

### Space Complexity

The space complexity is \(O(n)\), where \(n\) is the number of processes. This is because we are using an array of structures to store process information.

----