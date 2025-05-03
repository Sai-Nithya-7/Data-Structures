#include <iostream>
using namespace std;

class Graph {
private:
    struct Node {
        int vertex;
        Node* next;
    };

    Node** adjList;
    int vertices;

    bool searchNode(int u, int v) {
        Node* curr = adjList[u];
        while (curr != nullptr) {
            if (curr->vertex == v) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }


public:
    Graph(int v) {
        vertices = v;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; ++i) {
            Node* curr = adjList[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void Insert(int, int);
    void Delete(int, int);
    void Search(int, int);
    void Display();
};

int main() {
    int vertices, choice, u, v;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two vertices to insert edge (u v): ";
                cin >> u >> v;
                g.Insert(u, v);
                break;
            case 2:
                cout << "Enter two vertices to delete edge (u v): ";
                cin >> u >> v;
                g.Delete(u, v);
                break;
            case 3:
                cout << "Enter two vertices to search edge (u v): ";
                cin >> u >> v;
                g.Search(u, v);
                break;
            case 4:
                g.Display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

void Insert(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        Node* newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;

        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;

        cout << "Edge inserted successfully.\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Delete(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        bool deleted = false;

        Node* curr = adjList[u];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->vertex == v) {
                if (prev == nullptr) {
                    adjList[u] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                deleted = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        curr = adjList[v];
        prev = nullptr;
        while (curr != nullptr) {
            if (curr->vertex == u) {
                if (prev == nullptr) {
                    adjList[v] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                deleted = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (deleted) {
            cout << "Edge deleted successfully.\n";
        } else {
            cout << "Edge not found.\n";
        }
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Search(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        if (searchNode(u, v)) {
            cout << "Edge exists between " << u << " and " << v << ".\n";
        } else {
            cout << "No edge between " << u << " and " << v << ".\n";
        }
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Display() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << " -> ";
        Node* curr = adjList[i];
        while (curr != nullptr) {
            cout << curr->vertex << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
}