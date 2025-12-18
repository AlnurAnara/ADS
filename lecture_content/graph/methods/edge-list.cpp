#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    int weight;
};

const int MAXE = 1000;  // Maximum number of edges
Edge edges[MAXE];
int edgeCount = 0;
int n;  // Number of vertices

// Add edge
void addEdge(int u, int v, int weight = 1) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].weight = weight;
    edgeCount++;
}

// Print edge list
void printEdges() {
    cout << "Edge List:" << endl;
    for (int i = 0; i < edgeCount; i++) {
        cout << "(" << edges[i].u << ", " << edges[i].v;
        if (edges[i].weight != 1)
            cout << ", " << edges[i].weight;
        cout << ")" << endl;
    }
}

int main() {
    n = 4;  // Number of vertices

    // Add edges
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    printEdges();

    cout << "\nTotal edges: " << edgeCount << endl;

    return 0;
}