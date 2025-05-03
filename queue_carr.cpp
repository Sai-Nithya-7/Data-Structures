// Program to implement Circular Queue ADT using an Array of size 5

#include <iostream>
using namespace std;;

class queue_adt {
    private:
        int queue[5];
        int front;
        int back;
    
    public:
        queue_adt() {
            front = -1;
            back = -1;
            for (int i=0; i<5; i++) {
                queue[i] = 0;
            }
        }
        void EnQueue(int);
        void DeQueue();
        void Peek();
        void Display();
};

int main() {
    int choice;
    queue_adt q1;
    do {
        cout << "MENU:\n 1. EnQueue\n 2. DeQueue\n 3. Peek\n 4. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice) {
            case 1:
                int num;
                cout << "Enter the number:";
                cin >> num;
                q1.EnQueue(num);
                break;
            case 2:
                q1.DeQueue();
                break;
            case 3:
                q1.Peek();
                break;
            case 4:
                cout << "Exiting Program...";
                break;
            default:
                cout << "Invalid choice. 1-4 only\n";
        }
    }
    while(choice != 4);
    return 0;
}

// Function to Enqueue
void queue_adt::EnQueue(int num) {
    if (back == 4) {
        cout << "Queue is full. Can't enter more elements.\n";
        return;
    }
    if (front == -1) {
        front++;
    }
    queue[++back] = num;
    cout << "Element has been EnQueued\n";
    Display();
}

// Function to Dequeue
void queue_adt::DeQueue() {
    if (front == -1) {
        cout << "Queue is already empty.\n";
        return;
    }
    if (front == back) {
        front = -1;
        cout << "Element has been Dequeued.\n";
        Display();
        return;
    }
    front++;
    cout << "Element has been Dequeued.\n";
    Display();
}

// Function to Peek (display the 1st element)
void queue_adt::Peek() {
    if (front == -1) {
        cout << "Queue is empty.";
        return;
    }
    cout << "Peek (1st element): " << queue[front] << "\n";
}

// Function to Display the queue
void queue_adt::Display() {
    if (back == -1) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Current Queue:";
    for (int i=front; i <= back; i++) {
        cout << queue[i] << " ";
    }
    cout << "\n";
}