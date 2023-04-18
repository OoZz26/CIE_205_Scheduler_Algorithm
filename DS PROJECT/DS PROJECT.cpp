#include<iostream>
#include"Data Structures/Linked_List.h"
#include"Data Structures/QUEUE.h"
#include"Process/Process.h"
#include"RR_processor.h"
#include"FCFS_processor.h"
#include"PRIORITY_QUEUE.h"
#include"Scheduler.h"
#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
int main() {
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    PriorityQueue p1;
    Process* processes = new Process[num_processes];

    for (int i = 0; i < num_processes; i++) {
        int arrival_time, pid, cpu_time, io_request_number;
        cout << "Enter process #" << i + 1 << " Arrival time: ";
        cin >> arrival_time;

        cout << "Enter process #" << i + 1 << " ID: ";
        cin >> pid;

        cout << "Enter process #" << i + 1 << " CPU time: ";
        cin >> cpu_time;

        cout << "Enter process #" << i + 1 << " Number of I/O requests: ";
        cin >> io_request_number;

        vector<pair<int, int>> io_requests;

        for (int j = 0; j < io_request_number; j++) {
            int io_request_time, io_duration;
            cout << "Enter I/O request #" << j + 1 << " time for process #" << i + 1 << " : ";
            cin >> io_request_time;

            cout << "Enter I/O request #" << j + 1 << " duration for process #" << i + 1 << " : ";
            cin >> io_duration;

            io_requests.push_back(make_pair(io_request_time, io_duration));
        }
        
        processes[i].set_arrival_time(arrival_time);
        processes[i].set_id(pid);
        processes[i].set_cpu_time(cpu_time);
        processes[i].set_io(io_requests);
        p1.enqueue(&processes[i]);
    }
    p1.Display();
    
    
    
    FCFS_processor F1(4);
    RR_processor R1(5, 8);
    R1.add_process(processes);
    R1.ScheduleAlgo();
    F1.add_process(processes);
    F1.ScheduleAlgo();
    Scheduler S1;
    S1.LoadData("Test1.txt");
    
    //delete[] processes;
    return 0;
    


}