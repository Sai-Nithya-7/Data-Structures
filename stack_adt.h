#include<iostream>
using namespace std;

class stack_adt {
    private:
        struct node {
            char data;  
            struct node *next;
        } *TOS;
    public:
        stack_adt() {
            TOS = NULL;
        }
        bool Empty() {
            return TOS == NULL;
        }
        void Push(char ch) {
            node *newnode = new node;
            newnode->data = ch;
            newnode->next = TOS;
            TOS = newnode;
        }
        
        void Pop() {
            if (TOS == NULL) {
                cout << "Stack is empty\n";
                return;
            }
            node *temp = TOS;
            TOS = temp->next;
            delete temp;
        }
        
        char Peek() {  
            if (TOS == NULL) {
                cout << "Stack is empty\n";
                return '\0';  
            }
            return TOS->data;
        }     
};