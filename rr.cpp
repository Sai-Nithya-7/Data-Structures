// C++ to execute Round Robin Scheduling using Circular Linked List

#include<iostream>
#include "cll.h" 

using namespace std;

int time_slot;
cll processQueue; 

void execute() {
    if (processQueue.head == NULL) {
        cout << "No processes in the queue.\n";
        return;
    }

    int executionTime = processQueue.head->data;
    processQueue.delete_beginning();

    executionTime -= time_slot;

    if (executionTime > 0) {
        processQueue.insert_end(executionTime);
    } else {
        cout << "Process completed execution.\n";
    }
}

int main() {
    int choice, executionTime;
    cout << "Enter fixed time slot for Round Robin Scheduling: ";
    cin >> time_slot;
    
    do {
        cout << "\nMenu:\n 1. Insert Process\n 2. Execute Next Process\n 3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter execution time for the process: ";
                cin >> executionTime;
                processQueue.insert_end(executionTime);
                break;
            case 2:
                execute();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Enter from 1-3 only.";
        }
    } while (choice != 3);
    
    return 0;
}
