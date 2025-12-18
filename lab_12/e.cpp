#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 4e18;

/*Given a directed weighted graph (N ≤ 100), represented by its adjacency matrix,
you must:
Determine whether the graph contains a negative-weight cycle.
If yes, output:
“YES”
The number of vertices in the cycle
The actual cycle (any of them)*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    struct Edge { int u, v; long long w; };
    vector<Edge> edges;
    edges.reserve(n * n);

    // Read adjacency matrix
    vector<vector<long long>> a(n, vector<long long>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 100000) { // edge exists
                edges.push_back({i, j, a[i][j]});
            }
        }

    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);
    int x = -1;

    // Bellman-Ford
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // Recover cycle
    int y = x;
    for (int i = 0; i < n; i++)
        y = parent[y];

    vector<int> cycle;
    int cur = y;
    while (true) {
        cycle.push_back(cur);
        if (cur == y && cycle.size() > 1) break;
        cur = parent[cur];
    }

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int v : cycle) cout << v + 1 << " ";
    cout << "\n";

    return 0;
}
