#include <iostream>
using namespace std;

class Graph {
private:
    int adjMatrix[100][100];
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; ++i)
            for (int j = 0; j < vertices; ++j)
                adjMatrix[i][j] = 0;
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
        cout << "\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Matrix\n5. Exit\n";
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

void Graph::Insert(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        cout << "Edge inserted successfully.\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Graph::Delete(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        cout << "Edge deleted successfully.\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Graph::Search(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        if (adjMatrix[u][v] == 1)
            cout << "Edge exists between " << u << " and " << v << ".\n";
        else
            cout << "No edge between " << u << " and " << v << ".\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Graph::Display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}