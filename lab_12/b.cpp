#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*Red Riding Hood must travel from:
start → merchant → pharmacy → grandmother➡️ Find the shortest possible distance that allows visiting both merchant and pharmacy in any order.*/
using namespace std;

using ll = long long;
const ll INF = 4e18;

vector<ll> dijkstra(int src, const vector<vector<pair<int,ll>>>& g) {
    int n = g.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto &e : g[u]) {
            int v = e.first;
            ll w = e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,ll>>> g(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;

    auto ds = dijkstra(s, g);
    auto da = dijkstra(a, g);
    auto db = dijkstra(b, g);

    ll p1 = ds[a] + da[b] + db[f];
    ll p2 = ds[b] + db[a] + da[f];

    ll ans = min(p1, p2);
    if (ans >= INF) cout << -1;
    else cout << ans;
}
