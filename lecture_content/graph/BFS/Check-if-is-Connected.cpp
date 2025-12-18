#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int MAXN = 100;  // Maximum number of vertices
vector<int> adj[MAXN]; // Adjacency list representation

bool isConnected(Graph& g) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);
    int count = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                count++;
            }
        }
    }

    return count == n;
}
