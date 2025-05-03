// Header file to access all the cll functions

#ifndef CLL_H
#define CLL_H

#include <iostream>
using namespace std;

class cll {
    struct node {
        int data;
        struct node *next;
    } *head;

public:
    cll() { head = NULL; }

    void insert_beginning(int num) {
        node *newnode = new node;
        newnode->data = num;

        if (head == NULL) {
            newnode->next = newnode; 
            head = newnode;
        } else {
            node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
    }

    void insert_end(int num) {
        node *newnode = new node;
        newnode->data = num;

        if (head == NULL) {
            newnode->next = newnode;
            head = newnode;
        } else {
            node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void delete_beginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        
        node *delNode = head;
        temp->next = head->next;
        head = head->next;
        delete delNode;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        node *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node *temp = head;
        int pos = 1;

        do {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node *temp = head;
        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(Back to Head)\n";
    }
};

#endif
