//  Program to implement list ADT using array

#include<iostream>
using namespace std;

class list_adt {
  private:
    int current;
    int list[5];
  public:
    list_adt() {
    current = -1;
    for (int i=0;i<5;i++) {
        list[i] = 0;
     }
    }
    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    void delete_beginning();
    void delete_end();
    void delete_position(int);
    void search(int);
    void display();
    void rotate(int);
};

int main() {
    int choice,num,pos;
    list_adt l1;
    do {
    cout << "\n1. Insert at the beginning\n2. Insert at the end.\n3. Insert at position.\n4. Delete at the beginning.\n5. Delete at the end.\n6. Delete from a position.\n7. Search an element.\n8. Display the list.\n9. Rotate the list.\n10. Exit\n";
    cout << "Enter your choice:";
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "Enter number to insert:";
            cin >> num;
            l1.insert_beginning(num);
            break;
        case 2:
            cout << "Enter number to insert: ";
            cin >> num;
            l1.insert_end(num);
            break;
        case 3:
            cout << "Enter number to insert: ";
            cin >> num;
            cout << "Enter position to insert: ";
            cin >> pos;
            l1.insert_position(num, pos);
            break;
        case 4:
            l1.delete_beginning();
            break;
        case 5:
            l1.delete_end();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            l1.delete_position(pos);
            break;
        case 7:
            cout << "Enter number to search: ";
            cin >> num;
            l1.search(num);
            break;
        case 8:
            l1.display();
            break;
        case 9:
            cout << "Enter rotation count: ";
            cin >> num;
            l1.rotate(num);
            break;
        case 10:
            cout << "Exiting program ...";
            break;
        default:
            cout << "Invalid choice. Enter from 1-10 only";
        }
    }
    while (choice != 10);
    return 0;
}

//Function to Insert at the beginning
void list_adt::insert_beginning(int num) {
    if (current == 4) {
        cout << "List is full. Cannot insert.\n";
        return;
    }
    for (int i = current; i >= 0; i--) {
        list[i + 1] = list[i];
    }
    list[0] = num;
    current++;
    cout << "Number inserted at the beginning";
}

// Function to Insert at the end
void list_adt::insert_end(int num) {
    if (current == 4) {
        cout << "List is full. Cannot insert.\n";
        return;
    }
    list[++current] = num;
    cout << "Number inserted at the end";
}

// Function to Insert at a position
void list_adt::insert_position(int num, int pos) {
    if (current == 4 || pos < 0 || pos > current + 1) {
        cout << "Invalid position or list full.\n";
        return;
    }
    for (int i = current; i >= pos; i--) {
        list[i + 1] = list[i];
    }
    list[pos] = num;
    current++;
    cout << "Number inserted at the postion" << pos;
}

//Function to delete at the beginning
void list_adt::delete_beginning() {
    if (current == -1) {
        cout << "List is empty.\n";
        return;
    }
    for (int i = 0; i < current; i++) {
        list[i] = list[i + 1];
    }
    current--;
    cout << "Number deleted at the beginning";
}

// Function to Delete at the end
void list_adt::delete_end() {
    if (current == -1) {
        cout << "List is empty.\n";
        return;
    }
    current--;
    cout << "Number deleted at the end";
}

// Function to Delete at a position
void list_adt::delete_position(int pos) {
    if (pos < 0 || pos > current) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < current; i++) {
        list[i] = list[i + 1];
    }
    current--;
    cout << "Number deleted from the position" << pos;
}

// Function to Search an element in the list
void list_adt::search(int num) {
    for (int i = 0; i <= current; i++) {
        if (list[i] == num) {
            cout << "Element found at index: " << i << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

//Function to Display the list
void list_adt::display() {
    if (current == -1) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List elements: ";
    for (int i = 0; i <= current; i++) {
        cout << list[i] << " ";
    }
    cout << "\n";
}

// Function to rotate the LIST by 'k' elements
void list_adt::rotate(int k) {
    if (current == -1) {
        cout << "List is empty.\n";
        return;
    }
    k = k % (current + 1);
    if (k == 0) return;
    int temp[5];
    for (int i = 0; i <= current; i++) {
        temp[(i + k) % (current + 1)] = list[i];
    }
    for (int i = 0; i <= current; i++) {
        list[i] = temp[i];
    }
    cout << "The has successfully been rotated %d times" << k;
}
