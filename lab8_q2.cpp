// Program to implement Tree ADT using a Character Binary Tree

#include <iostream>
using namespace std;

class tree_adt {
    private:
        struct Node {
            char data;
            Node* left;
            Node* right;
        };
        Node* root;

        Node* createNode(char);
        Node* insertNode(Node*, char);

        void preorderTraversal(Node*);
        void inorderTraversal(Node*);
        void postorderTraversal(Node*);
        bool searchNode(Node*, char);

    public:
        tree_adt() {
            root = nullptr;
        }
        void Insert(char);
        void Preorder();
        void Inorder();
        void Postorder();
        void Search(char);
};

int main() {
    int choice;
    char value;
    tree_adt t1;

    do {
        cout << "MENU:\n 1. Insert\n 2. Preorder\n 3. Inorder\n 4. Postorder\n 5. Search\n 6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                t1.Insert(value);
                break;
            case 2:
                t1.Preorder();
                break;
            case 3:
                t1.Inorder();
                break;
            case 4:
                t1.Postorder();
                break;
            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                t1.Search(value);
                break;
            case 6:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice. 1-6 only\n";
        }
    } while (choice != 6);
    return 0;
}

// Creates a new node
tree_adt::Node* tree_adt::createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Inserts a node into the tree
void tree_adt::Insert(char data) {
    root = insertNode(root, data);
    cout << "Element has been Inserted\n";
}

// Recursive function to insert a node
tree_adt::Node* tree_adt::insertNode(Node* node, char data) {
    if (node == nullptr) {
        return createNode(data);
    }
    char direction;
    cout << "Insert " << data << " to (L)eft or (R)ight of " << node->data << "? ";
    cin >> direction;
    if (direction == 'L' || direction == 'l') {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }
    return node;
}

// Preorder Traversal
void tree_adt::Preorder() {
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";
}

void tree_adt::preorderTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Inorder Traversal
void tree_adt::Inorder() {
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";
}

void tree_adt::inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Postorder Traversal
void tree_adt::Postorder() {
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";
}

void tree_adt::postorderTraversal(Node* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Searches for a node in the tree
void tree_adt::Search(char data) {
    if (searchNode(root, data)) {
        cout << "Element " << data << " is found in the tree.\n";
    } else {
        cout << "Element " << data << " is NOT found in the tree.\n";
    }
}

bool tree_adt::searchNode(Node* node, char data) {
    if (node == nullptr) return false;
    if (node->data == data) return true;
    return searchNode(node->left, data) || searchNode(node->right, data);
}
