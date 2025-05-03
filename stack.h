#include <iostream>
using namespace std;

class stack_adt {
private:
    struct node {
        int data;  
        struct node* next;
    } *TOS;

public:
    stack_adt() {
        TOS = NULL;
    }

    bool Empty() {
        return TOS == NULL;
    }

    void Push(int value) {  
        node* newnode = new node;
        newnode->data = value;
        newnode->next = TOS;
        TOS = newnode;
    }

    void Pop() {
        if (TOS == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        node* temp = TOS;
        TOS = temp->next;
        delete temp;
    }

    int Peek() { 
        if (TOS == NULL) {
            cout << "Stack is empty\n";
            return -1; 
        }
        return TOS->data;
    }
};
