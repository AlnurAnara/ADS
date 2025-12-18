#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class DSU {
    vector<int> p;
    vector<int> R;

    DSU(int v) {
        for (int i = 0; i < v; i++) {
            p[i] = i;
            R[i] = 1;
        }
    }

    int find(int i) {
        if (p[i] == i) { 
            return i;
        } else {
            return p[i] = find(p[i]); 
        }
    }

   
    bool unite(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if (p1 != p2) {
            if (R[p1] > R[p2]) {
                p[p2] = p1;
            } else if (R[p1] < R[p2]) {
                p[p1] = p2;
            } else {
                p[p2] = p1;
                R[p1]++;
            }
            return true; 
        }
        return false; 
    }
};

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

// Global variables to store results
int V_GLOBAL;
int min_total_weight = 0;
vector<vector<int>> current_tree_edges;


int kruskal(vector<vector<int>> el, int V) {
    DSU dsu(V);
    sort(el.begin(), el.end(), cmp);
    int total_weight = 0;
    int count = 0;

    for(auto& edge: el){
        int x = edge[0]; int y = edge[1]; int w = edge[2];
        if dsu.find(x) != dsu.find(y){
            unite(x, y);
            total_weight += w;
            count++;

            if count == V - 1 break;
        }

        return total_weight;
    }
}

// 4. Recursive function to find ALL MSTs
// Note: We pass 'dsu' by VALUE (copy) to preserve state easily
void findAllMSTs(int idx, int edges_count, int current_w, DSU dsu, vector<vector<int>>& el) {
    
    // Pruning: If current weight exceeds min, stop
    if (current_w > min_total_weight) return;

    // Base Case: Found a valid tree
    if (edges_count == V_GLOBAL - 1) {
        if (current_w == min_total_weight) {
            cout << "MST Found: ";
            for (auto& edge : current_tree_edges) {
                cout << "(" << edge[0] << "-" << edge[1] << " w:" << edge[2] << ") ";
            }
            cout << endl;
        }
        return;
    }

    // If we ran out of edges
    if (idx == el.size()) return;

    // --- Logic: Include or Exclude current edge ---

    int u = el[idx][0];
    int v = el[idx][1];
    int w = el[idx][2];

    // Option 1: Try to INCLUDE this edge
    // We need a copy of the DSU for this path
    DSU next_dsu = dsu; 
    if (next_dsu.unite(u, v)) {
        current_tree_edges.push_back(el[idx]);
        findAllMSTs(idx + 1, edges_count + 1, current_w + w, next_dsu, el);
        current_tree_edges.pop_back(); // Backtrack
    }

    // Option 2: EXCLUDE this edge (Skip it)
    // Optimization: Do we have enough edges left?
    // (Total Edges - Current Index) >= (Needed - Taken)
    if ((el.size() - 1 - idx) >= (V_GLOBAL - 1 - edges_count)) {
        // We pass the ORIGINAL 'dsu' because we didn't change it here
        findAllMSTs(idx + 1, edges_count, current_w, dsu, el);
    }
}

int main() {
    // Example Input: 4 Vertices, 5 Edges
    int V = 4;
    int E = 5;
    V_GLOBAL = V;

    /* Format: {u, v, w} 
       Note: Vertices are 0-based (0 to 3) to match your DSU loop 
    */
    vector<vector<int>> el = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 1},
        {0, 3, 1},
        {0, 2, 2} 
    };

    // Step 1: Sort edges
    sort(el.begin(), el.end(), cmp);

    // Step 2: Get the target minimum weight
    min_total_weight = getMinWeight(el, V);

    if (min_total_weight == -1) {
        cout << "Graph is disconnected." << endl;
        return 0;
    }

    cout << "Minimum Weight: " << min_total_weight << endl;
    cout << "Generating all MSTs..." << endl;

    // Step 3: Find all trees matching that weight
    DSU initial_dsu(V);
    findAllMSTs(0, 0, 0, initial_dsu, el);

    return 0;
}