// Program to implement list ADT using Singly Linked List

#include<iostream>
using namespace std;
class list_adt {
    struct node {
        int data;
        struct node *next;
    } *head;
    public:
        list_adt() {
           head = NULL;
            }
        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int, int);
        void delete_beginning();
        void delete_end();
        void delete_position(int);
        void search(int);
        void display();
        void reverse_link();
        void display_rev_rec();
        void display_reverse();
};

int main() {
    list_adt list1;
    int num, choice;
    do {
        cout << "\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at position\n4. Delete at the beginning\n5. Delete at the end\n6. Delete from a position\n7. Search an element\n8. Display the list\n9. Display the list in reverse\n10. Reverse the list\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the number to be inserted: ";
                cin >> num;
                list1.insert_beginning(num);
                break;
            case 2:
                cout << "Enter the number to be inserted: ";
                cin >> num;
                list1.insert_end(num);
                break;
            case 3:
                int position;
                cout << "Enter the number to be inserted: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> position;
                list1.insert_position(num, position);
                break;
            case 4:
                list1.delete_beginning();
                break;
            case 5:
                list1.delete_end();
                break;
            case 6:
                cout << "Enter position to be deleted: ";
                cin >> position;
                list1.delete_position(position);
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> num;
                list1.search(num);
                break;
            case 8:
                list1.display();
                break;
            case 9:
                list1.display_reverse();
                break;
            case 10:
                list1.reverse_link();
                cout << "List reversed successfully!\n";
                break;
            case 11:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Enter from 1-11 only\n";
        }
    } while (choice != 11);
}

// Program to insert an element in the beginning
void list_adt::insert_beginning(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    cout << "Inserted\n";
}

// Program to insert an element in the end
void list_adt::insert_end(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
        cout << "Inserted\n";
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    newnode->next = NULL;
    temp->next = newnode;
}

// Function to insert element at given position
void list_adt::insert_position(int num, int position) {
    if (position == 0) {
        cout << "Invalid position.\n";
        return;
    }
    if (position == 1) {
            insert_beginning(num);
            return;
        }
    else {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    for (int i = 1; temp != NULL && i<position-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }
    newnode->data = num;
    newnode->next = temp->next;
    temp->next = newnode;
    cout << "Inserted at position " << position << " successfully\n";
    return;
    }
}

// Function to delete at the beginning
void list_adt::delete_beginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node *temp = head;
    head = temp->next;
    free(temp);
    cout << "Deleted successfully!\n";
}

// Function to delete at the end
void list_adt::delete_end() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    cout << "Deleted successfully!\n";
}

// Function to delete from a position
void list_adt::delete_position(int position) {
    if ( position < 1) {
        cout << "Invalid position\n";
        return;
    }
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (position == 1) {
        delete_beginning();
        return;
    }
    node *temp = head, *prev = NULL;
    for (int i = 1; temp && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Deleted successfully!\n";
}

// Function to search for an element
void list_adt::search(int num) {
    node *temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == num) {
            cout << "Element found at position " << position << "\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element not found\n";
}

// Function to display the list
void list_adt::display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "\n";
}

//Recursive function to display in reverse
void list_adt::display_reve_rec(node *temp) {
    if (!temp) return;
    display_rev_rec(temp->next);
    cout << temp->data << " <- ";
}

//Function to display in reverse
void list_adt::display_reverse() {
    display_rev_rec(head);
    cout << "NULL\n";
}

// Function to reverse the list
void list_adt::reverse_link() {
    node *prev = NULL, *current = head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
