// Program to implement Hash ADT using Separate Chaining with Arrays (Menu-Driven)

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int CHAIN_SIZE = 5; 

class SeparateChainingHash {
private:
    int hashTable[TABLE_SIZE][CHAIN_SIZE];
    int chainLengths[TABLE_SIZE];

public:
    SeparateChainingHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (int j = 0; j < CHAIN_SIZE; j++) {
                hashTable[i][j] = -1;
            }
            chainLengths[i] = 0;
        }
    }
    void Insert(int);
    void Delete(int);
    void Search(int);
    void Display();
};

int main() {
    int choice, num;
    SeparateChainingHash h;
    do {
        cout << "\nMENU:\n 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> num;
                h.Insert(num);
                break;
            case 2:
                cout << "Enter the number to delete: ";
                cin >> num;
                h.Delete(num);
                break;
            case 3:
                cout << "Enter the number to search: ";
                cin >> num;
                h.Search(num);
                break;
            case 4:
                h.Display();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}

// Function to Insert an element into the Hash Table
void SeparateChainingHash::Insert(int num) {
    int index = num % TABLE_SIZE;
    
    for (int i = 0; i < chainLengths[index]; i++) {
        if (hashTable[index][i] == num) {
            cout << "Element already exists.\n";
            return;
        }
    }
    
    if (chainLengths[index] >= CHAIN_SIZE) {
        cout << "Chain is full. Cannot insert.\n";
        return;
    }

    hashTable[index][chainLengths[index]] = num;
    chainLengths[index]++;
    cout << "Inserted successfully.\n";
}

// Function to Delete an element from the Hash Table
void SeparateChainingHash::Delete(int num) {
    int index = num % TABLE_SIZE;
    bool found = false;
    
    for (int i = 0; i < chainLengths[index]; i++) {
        if (hashTable[index][i] == num) {
            for (int j = i; j < chainLengths[index] - 1; j++) {
                hashTable[index][j] = hashTable[index][j+1];
            }
            chainLengths[index]--;
            hashTable[index][chainLengths[index]] = -1;
            cout << "Deleted successfully.\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Element not found.\n";
    }
}

// Function to search for an element in the Hash Table
void SeparateChainingHash::Search(int num) {
    int index = num % TABLE_SIZE;
    
    for (int i = 0; i < chainLengths[index]; i++) {
        if (hashTable[index][i] == num) {
            cout << "Element found at index " << index << ", position " << i << "\n";
            return;
        }
    }
    
    cout << "Element not found.\n";
}

// Function to display the Hash Table
void SeparateChainingHash::Display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (chainLengths[i] == 0) {
            cout << "empty";
        } else {
            for (int j = 0; j < chainLengths[i]; j++) {
                cout << hashTable[i][j] << " ";
            }
        }
        cout << endl;
    }
}