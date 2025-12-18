#include <iostream>
#include <vector>
using namespace std;

//with Edge List

struct Edge { int u, v, w; };

int main() {
    const long long INF = 4e18;
    int n, m, s; // vertices 0..n-1
    cin >> n >> m >> s;
    vector<Edge> edges(m);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    vector<long long> dist(n, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) break; // early exit if no updates
    }

    bool has_neg_cycle = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            has_neg_cycle = true;
            break;
        }
    }

    // dist holds shortest paths unless a reachable negative cycle exists
}