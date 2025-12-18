#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
bool recStack[MAXN];  // Vertices in current recursion stack
int n;

bool DFS_cycle_directed(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (DFS_cycle_directed(u))
                return true;
        }
        else if (recStack[u]) {
            // Found back edge to vertex in current path
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycleDirected() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS_cycle_directed(i))
                return true;
        }
    }

    return false;
}

int main() {
    n = 4;

    // Directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);  // Creates cycle: 1 -> 2 -> 3 -> 1

    cout << "Directed graph ";
    if (hasCycleDirected())
        cout << "has a cycle" << endl;
    else
        cout << "does NOT have a cycle" << endl;

    return 0;
}