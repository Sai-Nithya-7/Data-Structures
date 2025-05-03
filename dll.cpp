// C++ Program to impement list ADT using Doubly Linked List
#include<iostream>
using namespace std;
class list {
    struct node {
        struct node *prev;
        int data;
        struct node *next;
    }*head, *tail;
    int size;
    public:
        list() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int,int);
        void delete_beginning();
        void delete_end();
        void delete_position(int);
        void search(int);
        void display();
};

list l1;
int main()  {
    int choice,num, position;
    do {
        cout << "\nMenu:\n 1. Insert in the beginning\n 2. Insert at the end\n 3. Insert at position\n 4. Deletion at beginning\n 5. Deletion at the end\n 6. Deletion at position\n 7. Search\n 8. Display\n 9. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter number to insert:";
                cin >> num;
                l1.insert_beginning(num);
                break;
            case 2:
                cout << "Enter number to insert:";
                cin >> num;
                l1.insert_end(num);
                break;
            case 3:
                cout << "Enter number to insert:";
                cin >> num;
                cout << "Enter the position:";
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
                cout << "Exiting program ...";
                break;
            default:
                cout << "Invalid choice. Enter from 1-9 only";
        }
    }
    while (choice != 9);
    return 0;
}

// Function to insert at the beginning
void list::insert_beginning(int num) {
    node *newnode = new node;
    newnode->prev = NULL;
    newnode->next = head;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        cout << "Inserted!";
        size++;
        return;
    }
    else {
        head->prev = newnode;
        head = newnode;
    }
    cout << "Inserted!";
    size++;
}

//Function to insert at the end
void list::insert_end(int num) {
    node *newnode = new node;
    newnode->data = num ;
    newnode->prev = tail;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        cout << "Inserted!";
        size++;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    cout << "Inserted!";
    size++;
}

// Function to insert at a given position
void list::insert_position(int num, int pos) {
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        l1.insert_beginning(num);
        return;
    }
    if (pos == size+1) {
        l1.insert_end(num);
        return;
    }
    node *newnode = new node;
    newnode -> data = num;
    node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    size++;
    
}

// Function to delete from beginning
void list::delete_beginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    delete temp;
    size--;
    cout << "Deleted!\n";
}

// Function to delete from end
void list::delete_end() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    size--;
    cout << "Deleted!\n";
}

// Function to delete from a given position
void list::delete_position(int pos) {
    if (pos < 1 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1) {
        delete_beginning();
        return;
    }

    if (pos == size) {
        delete_end();
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    size--;
    cout << "Deleted!\n";
}

// Search for an element
void list::search(int num) {
    node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == num) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found!\n";
}

//Function to display the list
void list::display() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }
    node *temp = head;
    cout << "Doubly Linked List (Forward)\n";
    while (temp->next != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "\n";
    temp = tail;
    cout << "Doubly Linked List (Backward)\n";
    while (temp->prev != NULL) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << temp->data << "\n";
}