#include<iostream>
using namespace std;

class stack_adt {
    private:
        struct node {
            int data;
            struct node *next;
        } *TOS;
    public:
        stack_adt() {
            TOS = NULL;
            }
        void Push(int);
        void Pop();
        void Peek();
        void Display();
};

stack_adt stck;

int main() {
    int num, choice;
    do {
        cout << "\nMenu for STACK:\n1. Push - Add an element \n2. Pop - Delete an element \n3. Peek - Display the Top of the stack \n4. Display the stack \n5. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter number to add:";
                cin >> num;
                stck.Push(num);
                break;
            case 2:
                stck.Pop();
                break;
            case 3:
                stck.Peek();
                break;
            case 4:
                stck.Display();
                break;
            case 5:
                cout << "Exiting Program ...";
                break;
            default:
                cout << "Invalid choice. Enter from 1-5 only\n";
        }
    }
    while (choice != 5);
    return 0;
}

void stack_adt::Push(int num) {
    node *newnode = new node;
    newnode->data = num;
    newnode->next = TOS;
    TOS = newnode;
    cout << "Element added";
}

void stack_adt::Pop() {
    if (TOS == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    node *temp = TOS;
    TOS = temp->next;
    delete temp;
    cout << "The top element was popped.\n";
}

void stack_adt::Peek() {
    if (TOS == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    node *temp = TOS;
    cout << "The Top of stack:" << temp->data << "\n";
}

void stack_adt::Display() {
    if (TOS == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    node *temp = TOS;
    cout << "Stack:\n";
    while (temp->next != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << temp->data << "\n";
}