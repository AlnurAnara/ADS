/*Two people must travel from city 1 to city n, but:
Nugman uses only railways. Olzhas uses only airlines.
Airlines exist between all pairs WITHOUT railways.
Both travel time = 1 per edge.
They cannot meet on the way (except in 1 and n).
➡️ Find the minimum time such that both can reach city n without intersecting.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int INF = 1e9;

vector<int> bellmanFord(int n, vector<tuple<int,int,int>>& edges, int src) {
    vector<int> dist(n + 1, INF);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        bool changed = false;
        for (auto &e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> hasRail(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        hasRail[u][v] = hasRail[v][u] = true;
    }

    vector<tuple<int,int,int>> railEdges;
    vector<tuple<int,int,int>> airEdges;

    for (int u = 1; u <= n; u++)
        for (int v = u + 1; v <= n; v++) {
            if (hasRail[u][v]) {
                railEdges.emplace_back(u, v, 1);
                railEdges.emplace_back(v, u, 1);
            } else {
                airEdges.emplace_back(u, v, 1);
                airEdges.emplace_back(v, u, 1);
            }
        }

    auto distRail = bellmanFord(n, railEdges, 1);
    auto distAir  = bellmanFord(n, airEdges, 1);

    if (distRail[n] >= INF || distAir[n] >= INF) {
        cout << -1;
    } else {
        cout << max(distRail[n], distAir[n]);
    }
}
