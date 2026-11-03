# CPU Scheduling Simulator — C++

A CPU scheduling simulator built in C++ to explore how operating systems allocate CPU time among competing processes.

The project implements scheduling algorithms from scratch, tracks process execution, and calculates performance metrics to help understand how scheduling decisions affect waiting time and CPU utilization.

## Current Implementation

### First Come, First Served (FCFS)

The simulator currently implements non-preemptive FCFS scheduling. Processes are executed in arrival order, and once a process starts running, it continues until completion.

Current features:

- Process representation using a C++ `struct`
- Dynamic process storage using `vector`
- Arrival time and CPU burst time tracking
- Start time and completion time calculation
- Waiting time calculation
- Average waiting time calculation
- Handling CPU idle periods when a process arrives after the previous process has completed
- Terminal output displaying scheduling results

**Current limitation:** Processes are hardcoded and supplied in arrival order. Sorting, validation, and interactive process input have not yet been implemented.

## Technologies

- **Language:** C++
- **Standard:** C++17
- **Compiler:** GCC (g++)
- **Development environment:** Visual Studio Code

## How FCFS Works

FCFS schedules processes in the order they arrive.

For each process:

1. Determine when the CPU is available.
2. Start execution at the later of its arrival time or CPU availability.
3. Execute the process for its full CPU burst duration.
4. Calculate the completion and waiting times.
5. Advance the simulated CPU clock.

### Scheduling Formulas

```text
Start Time = max(Current Time, Arrival Time)

Completion Time = Start Time + Burst Time

Waiting Time = Start Time - Arrival Time

Average Waiting Time = Total Waiting Time / Number of Processes
```

These formulas apply to the current non-preemptive FCFS implementation.

## Example

Input workload:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1 | 0 | 5 |
| P2 | 1 | 3 |
| P3 | 2 | 1 |
| P4 | 3 | 2 |

Scheduling results:

| Process | Start Time | Completion Time | Waiting Time |
|---------|------------|-----------------|--------------|
| P1 | 0 | 5 | 0 |
| P2 | 5 | 8 | 4 |
| P3 | 8 | 9 | 6 |
| P4 | 9 | 11 | 6 |

**Average Waiting Time: 4.00 time units**

The simulation uses logical time units rather than executing real operating-system processes.

## Running the Project

### Requirements

- C++17-compatible compiler, such as GCC
- Terminal or command-line environment

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/cpu-scheduler.git
cd cpu-scheduler
```

Compile:

```bash
g++ -std=c++17 main.cpp -o scheduler
```

On Windows, you may name the executable `scheduler.exe` instead.

Run on Windows PowerShell:

```powershell
.\scheduler.exe
```

On Linux or macOS:

```bash
./scheduler
```

## Planned Features

- [x] Process data model
- [x] FCFS scheduling calculations
- [x] Waiting time and average waiting time
- [x] Terminal scheduling output
- [ ] Sort processes by arrival time
- [ ] Interactive process input
- [ ] ASCII Gantt chart with idle-period visualization
- [ ] Shortest Job First (SJF)
- [ ] Round Robin scheduling with configurable time quantum
- [ ] Turnaround and response time metrics
- [ ] CPU utilization and throughput metrics
- [ ] Algorithm comparison
- [ ] Automated tests and edge-case validation

## Learning Objectives

This project focuses on understanding:

- Non-preemptive and preemptive CPU scheduling
- Process arrival and execution timelines
- CPU idle time and scheduling efficiency
- C++ structures, vectors, and iteration
- Scheduling performance metrics
- Algorithmic trade-offs between different scheduling strategies

## Project Status

**In development — FCFS core implemented.**

The project will be extended incrementally with additional scheduling algorithms, visualization, and automated testing.
