// Function to C++ Program to implement List ADT using Circular Linked List
#include <iostream>
using namespace std;

class list {
    struct node {
        int data;
        struct node *next;
    } *head;
    
    int size; 

public:
    list() {
        head = NULL;
        size = 0;
    }

    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    void delete_beginning();
    void delete_end();
    void delete_position(int);
    void search(int);
    void display();
};

list l1;

int main()  {
    list l1;
    int choice,num;
    do {
        std::cout << "\nMenu:\n 1. Insert in the beginning\n 2. Insert at the end\n 3. Insert at position\n 4. Deletion at beginning\n 5. Deletion at the end\n 6. Deletion at position\n 7. Search\n 8. Display\n 9. Exit\n";
        std::cout << "Enter your choice:";
        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Enter number to insert:";
                std::cin >> num;
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
                cout << "Enter position: ";
                cin >> position;
                l1.insert_position(num, position);
                break;
            case 4:
                l1.delete_beginning();
                break;
            case 5:
                l1.delete_end();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                l1.delete_position(position);
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
                std::cout << "Exiting program ...";
                break;
            default:
                std::cout << "Invalid choice. Enter from 1-9 only";
        }
    }
    while (choice<9);
    return 0;
}

// Function to Insert at the beginning
void list::insert_beginning(int num) {
    node *newnode = new node;
    newnode->data = num;
    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    }
    else {
        newnode->next = head;
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        head = newnode;
    }
    std::cout << "Number inserted at the beginning";
}

// Function to Insert at end
void list::insert_end(int num) {
    if (head == NULL) {
        insert_beginning(num);
        return;
    }
    node *newnode = new node;
    newnode->data = num;
    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    size++;
    cout << "Inserted!\n";
}

// Function to Insert at position
void list::insert_position(int num, int pos) {
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        insert_beginning(num);
        return;
    }
    node *newnode = new node;
    newnode->data = num;
    node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    size++;
    cout << "Inserted!\n";
}

// Function to Delete from beginning
void list::delete_beginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    delete temp;
    size--;
    cout << "Deleted!\n";
}

// Function to Delete from end
void list::delete_end() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = head;
    }
    delete temp;
    size--;
    cout << "Deleted!\n";
}

// Function to Delete from position
void list::delete_position(int pos) {
    if (pos < 1 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        delete_beginning();
        return;
    }
    node *temp = head, *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    size--;
    cout << "Deleted!\n";
}

// Function to Search for an element
void list::search(int num) {
    node *temp = head;
    int pos = 1;
    do {
        if (temp->data == num) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Element not found!\n";
}

// Function to Display
void list::display() {
    if (head == NULL) {
        std::cout << "List is empty";
    }
    struct node *temp = head;
    std::cout << "Circular Linked List\n";
    do {
        std::cout << temp->data << "->";
        temp = temp->next;
    }
    while (temp != head);
    std::cout << temp->data << "\n";
}