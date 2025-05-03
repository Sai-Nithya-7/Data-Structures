#include <iostream>
#include <string>
#include "stack_adt.h"
using namespace std;

class Solution {
public:
    bool check_balance(string);
};

int main() {
    int choice;
    string input;
    Solution sol;
    
    do {
        cout << "1. Check if the string has valid parentheses\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter a string with parentheses: ";
                cin >> input;
                if(sol.check_balance(input))
                    cout << "The string has balanced parentheses.\n";
                else
                    cout << "The string has unbalanced parentheses.\n";
                break;
            case 2:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);
    
    return 0;
}

bool Solution::check_balance(string s) {
    int len = s.length();
    stack_adt stck;
    for (int i = 0; i < len; i++) {
        switch(s[i]) {
            case '(':
                stck.Push('(');
                break;
            case ')':
                if (stck.Empty() || stck.Peek() != '(')
                    return false;
                stck.Pop();
                break;
            default:
                cout << "Only '(' and ')' are valid characters\n";
                return false;
        }
    }
    return stck.Empty();
}