/*
给定一个 n × n 的矩阵，表示顶点间的连接情况：
a[i][j] = 0：顶点 i 和 j 之间已有边（连接费用为0）
a[i][j] > 0：顶点 i 和 j 之间可花 a[i][j] 费用建造边

目标
选择边（利用已有的0费用边 + 新建付费边），使得：
所有顶点连通
新建边的总费用最小
*/
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    const int INF = 1e9;

    vector<int> dist(n, INF);
    vector<bool> used(n, false);

    dist[0] = 0;
    long long total = 0;

    for (int it = 0; it < n; it++) {
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;
        }

        used[v] = true;
        total += dist[v];

        for (int u = 0; u < n; u++) {
            if (!used[u] && a[v][u] < dist[u]) {
                dist[u] = a[v][u];
            }
        }
    }

    cout << total;
    return 0;
}