#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;  // Maximum number of vertices
vector<int> adj[MAXN]; // Adjacency list representation

int countComponents(Graph& g) {
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;

            // BFS from vertex i
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }

    return components;
}