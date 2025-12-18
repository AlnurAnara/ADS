#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]); // path compression
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;          // already in same set
        if (rank[a] < rank[b]) swap(a, b); // union by rank
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int main() {
    int n = 5; // vertices 0..4
    vector<Edge> edges = {
        {0, 1, 1}, {0, 3, 3}, {1, 3, 2}, {1, 2, 4}, {1, 4, 5}, {3, 4, 1}, {2, 4, 6}
    };

    sort(edges.begin(), edges.end());
    DSU dsu(n);

    int mst_cost = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            mst_cost += e.w;
        }
        if ((int)mst.size() == n - 1) break;
    }

    cout << "MST cost: " << mst_cost << "\nEdges:\n";
    for (auto &e : mst) {
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";
    }
    return 0;
}