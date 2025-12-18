#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;

bool DFS_cycle(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (DFS_cycle(u, v))
                return true;
        }
        else if (u != parent) {
            // Visited vertex that is not parent = cycle found
            return true;
        }
    }

    return false;
}

bool hasCycle() {
    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS_cycle(i, -1))
                return true;
        }
    }

    return false;
}

int main() {
    // Example 1: Graph with cycle
    n = 4;
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    cout << "Graph ";
    if (hasCycle())
        cout << "has a cycle" << endl;
    else
        cout << "does NOT have a cycle" << endl;

    return 0;
}