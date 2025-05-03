// C++ Program to implement stack ADT using Array

#include<iostream>
using namespace std;

class stack_adt {
    private:
       int TOS;
       int stack[5];
    public:
        stack_adt() {
            TOS = -1;
            for (int i=0; i<=5; i++) {
                stack[i] = 0;
            }
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
    if (TOS == 4) {
        cout << "Stack is full. Cannot add more elements.\n";
        return;
    }
    stack[++TOS] = num;
    cout << "Element added";
}

void stack_adt::Pop() {
    if (TOS == -1) {
        cout << "Stack is empty.\n";
        return;
    }
    TOS--;
    cout << "The top element was popped.\n";
}

void stack_adt::Peek() {
    if (TOS == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "The Top of stack:" << stack[TOS] << "\n";
}

void stack_adt::Display() {
    if (TOS == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack:\n";
    for (int i=TOS; i >= 0; i--) {
        cout << stack[i] << "\n";
    }
}