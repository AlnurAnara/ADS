#include <iostream>
using namespace std;

const int MAXN = 100;  // Maximum number of vertices
int adj[MAXN][MAXN];   // Adjacency matrix
int n;                 // Number of vertices

// Add edge (undirected)
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Add directed edge
void addDirectedEdge(int u, int v) {
    adj[u][v] = 1;
}

// Add weighted edge
void addWeightedEdge(int u, int v, int weight) {
    adj[u][v] = weight;
    adj[v][u] = weight;
}

// Check if edge exists
bool hasEdge(int u, int v) {
    return adj[u][v] != 0;
}

// Print adjacency matrix
void printMatrix() {
    cout << "Adjacency Matrix:" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i << " [";
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    n = 4;  // Number of vertices

    // Initialize matrix with zeros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Add edges
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    printMatrix();

    // Print neighbors of vertex 0
    cout << "\nNeighbors of vertex 0: ";
    for (int i = 0; i < n; i++) {
        if (adj[0][i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}