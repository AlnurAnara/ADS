#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;     // Maximum number of vertices
vector<int> adj[MAXN];    // Adjacency list
int n;                    // Number of vertices

// Add edge (undirected)
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Add directed edge
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

// Check if edge exists
bool hasEdge(int u, int v) {
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v)
            return true;
    }
    return false;
}

// Print adjacency list
void printList() {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if (j < adj[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    n = 4;  // Number of vertices

    // Add edges
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    printList();

    // Print neighbors of vertex 0
    cout << "\nNeighbors of vertex 0: ";
    for (int i = 0; i < adj[0].size(); i++) {
        cout << adj[0][i] << " ";
    }
    cout << endl;

    return 0;
}



/*for weighted edges, we can use a pair to store the vertex and the weight
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<pair<int, int>> adj[MAXN];  // {neighbor, weight}
int n;

void addWeightedEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

void printWeightedList() {
    cout << "Weighted Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")";
            if (j < adj[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    n = 4;

    addWeightedEdge(0, 1, 5);
    addWeightedEdge(0, 3, 3);
    addWeightedEdge(1, 2, 7);
    addWeightedEdge(2, 3, 2);

    printWeightedList();

    return 0;
}*/