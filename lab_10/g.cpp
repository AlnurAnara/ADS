#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global variables to store graph and state
int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

// DFS to find the first cycle in the graph
// Colors: 0 = Unvisited, 1 = Visiting (Gray), 2 = Visited (Black)
bool dfs_find_cycle(int u) {
    color[u] = 1; // Mark as currently visiting
    for (int v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs_find_cycle(v)) return true;
        } else if (color[v] == 1) {
            // We found a back-edge to a node currently in recursion stack
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2; // Mark as completely visited
    return false;
}

// Helper DFS to check for cycles while ignoring a specific edge (u->v)
bool check_cycle_ignoring_edge(int u, vector<int>& col, int skip_u, int skip_v) {
    col[u] = 1;
    for (int v : adj[u]) {
        // Logically remove the edge skip_u -> skip_v
        if (u == skip_u && v == skip_v) continue; 
        
        if (col[v] == 1) return true; // Cycle detected
        if (col[v] == 0) {
            if (check_cycle_ignoring_edge(v, col, skip_u, skip_v)) return true;
        }
    }
    col[u] = 2;
    return false;
}

// Wrapper function to check if the whole graph is acyclic after removing edge (u, v)
bool is_acyclic_after_removal(int u, int v) {
    vector<int> col(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            if (check_cycle_ignoring_edge(i, col, u, v)) return false;
        }
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Step 1: Find if there is any cycle initially
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;
    
    bool cycle_found = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs_find_cycle(i)) {
            cycle_found = true;
            break;
        }
    }

    // If no cycle initially, condition is satisfied (removing 0 or any non-cycle edge works)
    if (!cycle_found) {
        cout << "YES" << endl;
        return 0;
    }

    // Step 2: Retrieve all edges belonging to the found cycle
    vector<pair<int, int>> edges_to_test;
    
    // Add the back-edge that closed the cycle
    edges_to_test.push_back({cycle_end, cycle_start});
    
    // Backtrack from cycle_end to cycle_start to get the rest of the edges
    int curr = cycle_end;
    while (curr != cycle_start) {
        int prev = parent[curr];
        edges_to_test.push_back({prev, curr});
        curr = prev;
    }

    // Step 3: Try removing each edge in this cycle one by one
    // If removing an edge makes the ENTIRE graph acyclic, print YES.
    for (auto& edge : edges_to_test) {
        if (is_acyclic_after_removal(edge.first, edge.second)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // If we tried all edges in the cycle and other cycles still remained
    cout << "NO" << endl;

    return 0;
}