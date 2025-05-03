// C++ Program to implement a Priority Queue using a max heap

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* heap;
    int cap;
    int size;

    // Helper functions for heap operations
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }
    
    void heapify(int i);
    void swap(int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

public:
    PriorityQueue(int limit);
    ~PriorityQueue();
    
    void insert(int key);
    void deleteMax(); 
    void display();
    void search(int key); 
    void heapSort();
    void isEmpty(bool& result) { result = (size == 0); } 
    void isFull(bool& result) { result = (size == cap); } 
    void getSize(int& result) { result = size; } 
};

// Constructor
PriorityQueue::PriorityQueue(int limit) {
    cap = limit;
    size = 0;
    heap = new int[cap];
}

// Destructor
PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

int main() {
    int choice, element, cap;
    bool isEmpty, isFull;
    
    cout << "Enter the size of the Priority Queue: ";
    cin >> cap;
    
    PriorityQueue pq(cap);
    
    do {
        cout << "\nMENU:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                pq.isFull(isFull);
                if(isFull) {
                    cout << "Priority Queue is full!\n";
                } else {
                    cout << "Enter element to insert: ";
                    cin >> element;
                    pq.insert(element);
                    cout << element << " inserted successfully.\n";
                }
                break;
                
            case 2:
                pq.isEmpty(isEmpty);
                if(isEmpty) {
                    cout << "Priority Queue is empty!\n";
                } else {
                    pq.deleteMax();
                }
                break;
                
            case 3:
                pq.isEmpty(isEmpty);
                if(isEmpty) {
                    cout << "Priority Queue is empty!\n";
                } else {
                    cout << "Priority Queue elements: ";
                    pq.display();
                }
                break;
                
            case 4:
                pq.isEmpty(isEmpty);
                if(isEmpty) {
                    cout << "Priority Queue is empty!\n";
                } else {
                    cout << "Enter element to search: ";
                    cin >> element;
                    pq.search(element);
                }
                break;
                
            case 5:
                pq.isEmpty(isEmpty);
                if(isEmpty) {
                    cout << "Priority Queue is empty!\n";
                } else {
                    pq.heapSort();
                    cout << "Heap Sort completed.\n";
                }
                break;
                
            case 6:
                cout << "Exiting program...\n";
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}

// Function to maintain the max heap property
void PriorityQueue::heapify(int i) {
    int max = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    if(left < size && heap[left] > heap[max])
        max = left;
    
    if(right < size && heap[right] > heap[max])
        max = right;
    
    if(max != i) {
        swap(heap[i], heap[max]);
        heapify(max);
    }
}

// Function to insert a new element into the priority queue
void PriorityQueue::insert(int key) {
    if(size == cap) {
        cout << "Overflow: Could not insert key\n";
        return;
    }
    int i = size;
    heap[i] = key;
    size++;
    
    while(i != 0 && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// Function to remove the maximum element
void PriorityQueue::deleteMax() {
    if(size <= 0) {
        cout << "Error: Priority Queue is empty\n";
        return;
    }
    
    cout << "Deleted element: " << heap[0] << endl;
    
    if(size == 1) {
        size--;
        return;
    }
    
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

// Function to display all elements in the priority queue
void PriorityQueue::display() {
    if(size <= 0) {
        cout << "Empty\n";
        return;
    }
    
    for(int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// Function to search for an element in the priority queue
void PriorityQueue::search(int key) {
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(heap[i] == key) {
            found = true;
            break;
        }
    }
    
    if(found) {
        cout << key << " found in the Priority Queue.\n";
    } else {
        cout << key << " not found in the Priority Queue.\n";
    }
}

// Function to sort the elements using heap sort 
void PriorityQueue::heapSort() {
    int* tempHeap = new int[size];
    for (int i = 0; i < size; i++) {
        tempHeap[i] = heap[i];
    }

    int tempSize = size;
    for (int i = tempSize - 1; i > 0; i--) {
        swap(tempHeap[0], tempHeap[i]);

        tempSize--;

        int maxv = 0;
        int left = 2 * maxv + 1;
        int right = 2 * maxv + 2;

        while (left < tempSize) {
            int maxInd = maxv;
            if (tempHeap[left] > tempHeap[maxInd])
                maxInd = left;
            if (right < tempSize && tempHeap[right] > tempHeap[maxInd])
                maxInd = right;

            if (maxInd == maxv)
                break;

            swap(tempHeap[maxv], tempHeap[maxInd]);
            maxv = maxInd;
            left = 2 * maxv + 1;
            right = 2 * maxv + 2;
        }
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < size; i++)
        cout << tempHeap[i] << " ";
    cout << endl;

    delete[] tempHeap;
}