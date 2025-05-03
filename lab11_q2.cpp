// Program to implement Hash ADT using Quadratic Probing (Menu-Driven)

#include <iostream>
using namespace std;

class QuadraticHash {
private:
    int hashTable[10];

public:
    QuadraticHash() {
        for (int i = 0; i < 10; i++) {
            hashTable[i] = -1;
        }
    }
    void Insert(int);
    void Delete(int);
    void Search(int);
    void Display();
};

int main() {
    int choice, num;
    QuadraticHash h;
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

void QuadraticHash::Insert(int num) {
    int index = num % 10;
    int i = 1;
    int originalIndex = index;
    int firstDeletedIndex = -1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == num) {
            cout << "Element already exists.\n";
            return;
        }
        if (hashTable[index] == -2 && firstDeletedIndex == -1) {
            firstDeletedIndex = index;
        }
        index = (originalIndex + i * i) % 10;
        i++;
        if (i == 10) break;
    }

    if (firstDeletedIndex != -1) {
        hashTable[firstDeletedIndex] = num;
        cout << "Inserted successfully.\n";
    } else if (hashTable[index] == -1) {
        hashTable[index] = num;
        cout << "Inserted successfully.\n";
    } else {
        cout << "Hash table is full.\n";
    }
}

void QuadraticHash::Delete(int num) {
    int index = num % 10;
    int i = 1;
    int originalIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == num) {
            hashTable[index] = -2;
            cout << "Deleted successfully.\n";
            return;
        }
        index = (originalIndex + i * i) % 10;
        i++;
        if (i == 10) break;
    }
    cout << "Element not found.\n";
}

void QuadraticHash::Search(int num) {
    int index = num % 10;
    int i = 1;
    int originalIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == num) {
            cout << "Element found at index " << index << "\n";
            return;
        }
        index = (originalIndex + i * i) % 10;
        i++;
        if (i == 10) break;
    }
    cout << "Element not found.\n";
}

void QuadraticHash::Display() {
    cout << "Hash Table: ";
    for (int i = 0; i < 10; i++) {
        if (hashTable[i] >= 0) cout << hashTable[i] << " ";
        else cout << "- ";
    }
    cout << endl;
}