#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Process {
    int id; 
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int waitingTime;
};

int main () {
    vector<Process> processes;

    processes.push_back({1, 0, 5});
    processes.push_back({2, 1, 3});
    processes.push_back({3, 2, 1});
    processes.push_back({4, 3, 2});

    cout << "CPU Scheduling Algorithm FCFS";

    int currentTime = 0;

    int totalWaitingTime = 0;

    for (int i = 0; i < processes.size(); i++) {
        processes[i].startTime = max(currentTime, processes[i].arrivalTime);
        processes[i].completionTime = processes[i].startTime + processes[i].burstTime;
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;
        totalWaitingTime += processes[i].waitingTime;

        cout << "\n" << "P" << processes[i].id << "\t"
        << "Arrival Time: " << processes[i].arrivalTime << "\t"
        << "Burst Time: " << processes[i].burstTime << "\t"
        << "Start Time: " << processes[i].startTime << "\t"
        << "Completion Time: "<< processes[i].completionTime << "\t"
        << "Waiting Time: " << processes[i].waitingTime << "\n";

        currentTime = processes[i].completionTime;
    }
    double averageWaitingTime = (double)totalWaitingTime / processes.size();
    cout << "\nAverage Waiting Time: "<< fixed << setprecision(2) << averageWaitingTime <<"\n";

    return 0;
}