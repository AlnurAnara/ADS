#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_component(int start,
                   const vector<vector<int>>& adj,
                   vector<bool>& visited,
                   vector<int>& component) {
    queue<int> q;

    visited[start] = true;      // 标记起点已访问
    q.push(start);              // 起点入队

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        component.push_back(v); // 这个点属于当前连通块

        // 遍历 v 的所有邻居
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;  // 没见过 → 马上标记
                q.push(u);          // 排队等待处理
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n: 顶点数(默认 0..n-1)，m: 边数

    // 邻接表：adj[v] 里存 v 的所有邻居
    vector<vector<int>> adj(n);

    // 读入无向边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // 无向图：两边都要加
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components; // 存所有连通分量

    // 遍历所有顶点，找“没被访问过的起点”
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            vector<int> comp;               // 当前连通块
            bfs_component(v, adj, visited, comp);
            components.push_back(comp);     // 收集这一个连通块
        }
    }

    // 输出所有连通分量
    cout << "Number of components: " << components.size() << "\n";
    for (int i = 0; i < (int)components.size(); i++) {
        cout << "Component " << i << ": ";
        for (int v : components[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
