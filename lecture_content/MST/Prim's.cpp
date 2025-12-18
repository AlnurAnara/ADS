#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n = 5; // vertices 0..4
    vector<vector<pair<int,int>>> g(n);
    auto add_edge = [&](int u, int v, int w) {
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    };

    add_edge(0, 1, 1);
    add_edge(0, 3, 3);
    add_edge(1, 3, 2);
    add_edge(1, 2, 4);
    add_edge(1, 4, 5);
    add_edge(3, 4, 1);
    add_edge(2, 4, 6);

    vector<bool> in_mst(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 0;
    pq.push({0, start});
    int total = 0, chosen = 0;

    while (!pq.empty() && chosen < n) {
        auto [w, v] = pq.top(); pq.pop();
        if (in_mst[v]) continue;
        in_mst[v] = true;
        total += w;
        chosen++;

        for (auto [to, cost] : g[v]) {
            if (!in_mst[to]) pq.push({cost, to});
        }
    }

    cout << "MST cost: " << total << "\n";
    return 0;
}