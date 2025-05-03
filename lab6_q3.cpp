#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

class Evaluator {
    public:
        bool isOperator(char);
        int precedence(char);
        string infixToPostfix(string);
        int evaluatePostfix(string);
};

string storedInfix;

int main() {
    int choice;
    do {
        cout << "\n1. Get Infix Expression\n2. Convert Infix to Postfix\n3. Evaluate Postfix Expression\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                getline(cin, storedInfix);
                cout << "Expression stored successfully!\n";
                break;
            case 2:
                if (storedInfix.empty()) {
                    cout << "No infix expression stored!\n";
                } else {
                    string postfix = infixToPostfix(storedInfix);
                    cout << "Postfix Expression: " << postfix << endl;
                }
                break;
            case 3:
                if (storedInfix.empty()) {
                    cout << "No infix expression stored!\n";
                } else {
                    string postfix = infixToPostfix(storedInfix);
                    int result = evaluatePostfix(postfix);
                    cout << "Result: " << result << endl;
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}

// Function to check if a character is an operator
bool Evaluator::isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

// Function to get precedence of an operator
int precedence(char op) {
    switch (op) {
        case '=': {
            return 1;
        }
        case '+': {
            return 2;
        }
        case '-': {
            return 2;
        }
        case '*': {
            return 3;
        }
        case '/': {
            return 3;
        }
        case '%': {
            return 3;
        }
        default: {
            return 0;
        }
    }
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack_adt opStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix += ch; 
        } 
        else if (isOperator(ch)) {
            while (!opStack.Empty() && precedence(opStack.Peek()) >= precedence(ch)) {
                postfix += opStack.Peek();
                opStack.Pop();
            }
            opStack.Push(ch);
        } 
        else if (ch == '(') {
            opStack.Push(ch);
        } 
        else if (ch == ')') {
            while (!opStack.Empty() && opStack.Peek() != '(') {
                postfix += opStack.Peek();
                opStack.Pop();
            }
            opStack.Pop();
        }
    }

    while (!opStack.Empty()) {
        postfix += opStack.Peek();
        opStack.Pop();
    }
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack_adt evalStack;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            evalStack.Push(ch); 
        } 
        else if (isOperator(ch)) {
            int val2 = evalStack.Peek() - '0'; evalStack.Pop();
            int val1 = evalStack.Peek() - '0'; evalStack.Pop();
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '%': result = val1 % val2; break;
                case '=': result = val2; break;
            }
            evalStack.Push(result + '0');
        }
    }
    return evalStack.Peek() - '0';
}
