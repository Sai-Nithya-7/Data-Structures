// Program to process a string by removing '+' and its left non-'+' character using Stack ADT

#include <iostream>
#include <stack>
using namespace std;

class stack_adt {
    private:
        stack<char> s;
    
    public:
        void ProcessString(string);
};

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    stack_adt obj;
    obj.ProcessString(input);
    
    return 0;
}

void stack_adt::ProcessString(string input) {
    stack<char> tempStack;

    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop();
            }
        } else {
            s.push(ch);
        }
    }

    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    cout << "Processed String: ";
    while (!tempStack.empty()) {
        cout << tempStack.top();
        tempStack.pop();
    }
    cout << "\n";
}