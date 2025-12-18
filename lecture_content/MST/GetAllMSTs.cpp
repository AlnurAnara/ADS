#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


struct Edge {
    int u, v, weight, id;
};

// Comparator for sorting edges
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) with Rollback support
// We need rollback to undo changes when backtracking
struct DSU {
    vector<int> parent;
    vector<int> sz; // Size of component to balance tree
    // Stack to store history for rollback: {child_node, parent_was_same?}
    // We only need to store the child whose parent changed.
    vector<pair<int, int>> history; 

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    int find(int i) {
        // Note: No path compression here because it makes rollback difficult/expensive.
        // We rely on union-by-size to keep height logarithmic.
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }

    // Returns true if merged, false if already connected
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Union by size: attach smaller tree to larger tree
            if (sz[root_i] < sz[root_j])
                swap(root_i, root_j);
            
            // Make root_i the parent of root_j
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            
            // Record change for rollback
            history.push_back({root_j, root_i}); 
            return true;
        }
        
        // Push a dummy marker indicating no merge happened
        history.push_back({-1, -1}); 
        return false;
    }

    void rollback() {
        pair<int, int> lastOp = history.back();
        history.pop_back();

        if (lastOp.first != -1) {
            int child = lastOp.first;
            int par = lastOp.second;
            
            parent[child] = child; // Reset parent
            sz[par] -= sz[child];  // Revert size
        }
    }
};

// Global variables
int N, M;
vector<Edge> edges;
vector<Edge> current_mst;
int min_mst_weight = 0;

// 1. Standard Kruskal's to find the target MST weight
int getMSTWeight() {
    DSU dsu(N + 1);
    int weight = 0;
    int count = 0;
    
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            weight += edge.weight;
            count++;
        }
        // Clean up the history stack since we are using the DSU struct 
        // that records history, but we don't need rollback here.
        // (In a pure Kruskal implementation we wouldn't use the history stack, 
        // but reusing the struct saves code).
    }
    
    if (count < N - 1) return -1; // Graph not connected
    return weight;
}

// 2. Backtracking function to find all MSTs
void findAllMSTs(int edge_idx, int edges_count, int current_weight, DSU& dsu) {
    
    // Optimization: Pruning
    // If current weight exceeds min MST weight, stop.
    if (current_weight > min_mst_weight) return;
    
    // Base Case: We have selected V-1 edges
    if (edges_count == N - 1) {
        if (current_weight == min_mst_weight) {
            cout << "Found MST: ";
            for (const auto& edge : current_mst) {
                cout << "(" << edge.u << "-" << edge.v << " w:" << edge.weight << ") ";
            }
            cout << endl;
        }
        return;
    }

    // If we ran out of edges
    if (edge_idx == M) return;

    // --- Recursion Logic ---

    // Strategy: We have two choices for the current edge: Include it or Exclude it.
    
    // Choice 1: Try to Include edges[edge_idx]
    int u = edges[edge_idx].u;
    int v = edges[edge_idx].v;
    int w = edges[edge_idx].weight;

    // Check if adding this edge creates a cycle
    bool merged = dsu.unite(u, v);
    
    if (merged) {
        // If merged successfully (no cycle), proceed
        current_mst.push_back(edges[edge_idx]);
        
        findAllMSTs(edge_idx + 1, edges_count + 1, current_weight + w, dsu);
        
        // Backtrack
        current_mst.pop_back();
        dsu.rollback(); // Undo the union
    } else {
        // Edge formed a cycle, we still need to pop the history marker
        // from our specific DSU implementation
        dsu.rollback(); 
    }

    // Choice 2: Exclude edges[edge_idx]
    // Optimization: Only skip if it's possible to form a tree with remaining edges.
    // Remaining needed: (N - 1) - edges_count
    // Remaining available: M - (edge_idx + 1)
    if (M - (edge_idx + 1) >= (N - 1) - edges_count) {
        
        // Additional Optimization: 
        // If we skipped a necessary edge (bridges) we might fail later, 
        // but calculating bridges dynamically is expensive. 
        // We rely on the weight check to prune bad branches.
        
        findAllMSTs(edge_idx + 1, edges_count, current_weight, dsu);
    }
}

int main() {
    // Example Input
    // First line: Vertices (N), Edges (M)
    // Next M lines: u v w
    
    cout << "Enter number of vertices (N) and edges (M): ";
    if (!(cin >> N >> M)) return 0;

    edges.resize(M);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].id = i; // Keep track of original index if needed
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Step 2: Calculate the Minimum Spanning Tree Weight
    min_mst_weight = getMSTWeight();

    if (min_mst_weight == -1) {
        cout << "Graph is disconnected. No MST." << endl;
        return 0;
    }

    cout << "Minimum MST Weight is: " << min_mst_weight << endl;
    cout << "Generating all MSTs..." << endl;

    // Step 3: Find all combinations
    DSU dsu(N + 1); // 1-based indexing support
    findAllMSTs(0, 0, 0, dsu);

    return 0;
}


/*
input:                
4 5
1 2 1
2 3 1
3 4 1
1 4 1
1 3 2

output:
Minimum MST Weight is: 3
Generating all MSTs...
Found MST: (1-2 w:1) (2-3 w:1) (3-4 w:1) 
Found MST: (1-2 w:1) (2-3 w:1) (1-4 w:1) 
Found MST: (1-2 w:1) (3-4 w:1) (1-4 w:1) 
Found MST: (2-3 w:1) (3-4 w:1) (1-4 w:1)
*/