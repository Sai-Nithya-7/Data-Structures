#include <iostream>
#include <climits>
using namespace std;

class Graph {
private:
    struct Edge {
        int src, dest, weight;
    };

    struct Node {
        int vertex;
        int weight;
        Node* next;
    };

    Node** adjList;
    int vertices;
    int edgeCount;
    Edge* edges;

    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < vertices; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    int findParent(int parent[], int i) {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    void unionSets(int parent[], int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    void sortEdges() {
        for (int i = 0; i < edgeCount-1; i++)
            for (int j = 0; j < edgeCount-i-1; j++)
                if (edges[j].weight > edges[j+1].weight)
                    swap(edges[j], edges[j+1]);
    }

public:
    Graph(int v) {
        vertices = v;
        adjList = new Node*[vertices];
        edges = new Edge[vertices*vertices];
        edgeCount = 0;
        for (int i = 0; i < vertices; i++)
            adjList[i] = nullptr;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* curr = adjList[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adjList;
        delete[] edges;
    }

    void addEdge(int, int, int);
    void Prims();
    void Kruskals();
    void Dijkstra(int);
};

int main() {
    int V, choice, u, v, w, src;
    
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);
    
    do {
        cout << "\nMENU:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Run Prim's MST Algorithm\n";
        cout << "4. Run Kruskal's MST Algorithm\n";
        cout << "5. Run Dijkstra's Shortest Path Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter edge. ";
                cout << "Enter u:"
                cin >> u ;
                cout << "Enter v:";
                cin >> v;
                cout << "Enter weight:";
                cin >> w;
                g.addEdge(u, v, w);
                break;
            case 2:
                g.displayGraph();
                break;
            case 3:
                g.Prims();
                break;
            case 4:
                g.Kruskals();
                break;
            case 5:
                cout << "Enter source vertex: ";
                cin >> src;
                g.Dijkstra(src);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}

void addEdge(int u, int v, int w) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertices! Must be between 0 and " << vertices-1 << endl;
            return;
        }

        Node* newNode = new Node{v, w, adjList[u]};
        adjList[u] = newNode;

        newNode = new Node{u, w, adjList[v]};
        adjList[v] = newNode;

        edges[edgeCount++] = {u, v, w};
        cout << "Edge added between " << u << " and " << v << " with weight " << w << endl;
}

void Prims() {
    if (edgeCount == 0) {
        cout << "Graph has no edges!\n";
        return;
    }

    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];

    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices-1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        Node* curr = adjList[u];
        while (curr != nullptr) {
            int v = curr->vertex;
            int weight = curr->weight;
            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            curr = curr->next;
        }
    }

    cout << "\nPrim's MST:\nEdge \tWeight\n";
    for (int i = 1; i < vertices; i++)
        cout << parent[i] << " - " << i << " \t" << key[i] << endl;
}

void Kruskals() {
    if (edgeCount == 0) {
        cout << "Graph has no edges!\n";
        return;
    }

    sortEdges();
    int parent[vertices];
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    cout << "\nKruskal's MST:\nEdge \tWeight\n";
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int set_u = findParent(parent, u);
        int set_v = findParent(parent, v);

        if (set_u != set_v) {
            cout << u << " - " << v << " \t" << edges[i].weight << endl;
            unionSets(parent, set_u, set_v);
        }
    }
}

void Dijkstra(int src) {
    if (src < 0 || src >= vertices) {
        cout << "Invalid source vertex!\n";
        return;
    }

    int dist[vertices];
    bool sptSet[vertices];

    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < vertices-1; count++) {
        int u = minKey(dist, sptSet);
        sptSet[u] = true;

        Node* curr = adjList[u];
        while (curr != nullptr) {
            int v = curr->vertex;
            int weight = curr->weight;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
            curr = curr->next;
        }
    }

    cout << "\nDijkstra's Shortest Paths from " << src << ":\nVertex \tDistance\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " \tUnreachable\n";
        else
            cout << i << " \t" << dist[i] << endl;
    }
}

void displayGraph() {
    cout << "\nCurrent Graph:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << " -> ";
        Node* curr = adjList[i];
        while (curr != nullptr) {
            cout << curr->vertex << "(" << curr->weight << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
}