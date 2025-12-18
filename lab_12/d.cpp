#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* There are n cities, each located at coordinate (xi,yi) on a 2D plane.
Find the minimum age required to be able to travel from city 1 to city n.*/
using ll = long long;
const ll INF = 4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll,ll>> city(n);
    for (int i = 0; i < n; i++)
        cin >> city[i].first >> city[i].second;

    // Precompute all pairwise Manhattan distances (complete graph)
    auto distMan = [&](int i, int j) {
        return llabs(city[i].first - city[j].first) 
             + llabs(city[i].second - city[j].second);
    };

    vector<ll> dist(n, INF);
    dist[0] = 0;

    // Minimax Dijkstra
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (v == u) continue;
            ll w = distMan(u, v);
            ll newCost = max(dist[u], w);
            if (dist[v] > newCost) {
                dist[v] = newCost;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[n-1] << "\n";
    return 0;
}
