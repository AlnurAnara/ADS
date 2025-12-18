#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*The developers give Arman a list of requirements, 
which indicates which quest must be completed in order to open the next one. 
Help Arman determine whether is it possible to complete this game, 
and if possible, output one of the scenarios for the passage.

*/
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        indegree[j]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() != n) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < n; i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}