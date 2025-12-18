#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main() {
    int n, m, s; // vertices are 0..n-1
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        // add g[v].push_back({u, w}); for an undirected graph
    }

    vector<int> d(n, INF), p(n, -1);
    vector<char> used(n, false);
    d[s] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (v == -1 || d[v] == INF)
            break;
        used[v] = true;

        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    // d now holds shortest paths from s; p stores the tree for reconstruction
}


/*
      (2)         (2)
 0 --------> 1 --------> 3
 |           \          |
 |(5)         \(1)      |(1)
 v             v         v
 2 ----------> 5 ------> 4
       (3)

       

Initialization

dist = [0, INF, INF, INF, INF], used = [F, F, F, F, F].
Iteration details (select the unused vertex with the smallest distance, then relax its edges):

Step	Picked vertex	Relaxations performed	Updated dist
1	    0 (dist = 0)	(0→1, +2), (0→2, +5)	[0, 2, 5, INF, INF]
2	    1 (dist = 2)	(1→3, +2), (1→5, +1)	[0, 2, 3, 4, INF] (better path to 2)
3	    2 (dist = 3)	(2→3, +3)	[0, 2, 3, 4, INF] (no improvement vs. 4)
4	    3 (dist = 4)	(3→4, +1)	[0, 2, 3, 4, 5]
5	    4 (dist = 5)	No outgoing edges	[0, 2, 3, 4, 5]
All vertices become visited, and the final distances [0, 2, 3, 4, 5] match the shortest paths from 0.
*/
step 1: Pick vertex 0 (dist=0), relax edges to 1 and 2.
0  1  2  3  4  5  
T  F  F  F  F  F
0  2  5

step 2: Pick vertex 1 (dist=2), relax edges to 3 and 2.
0  1  2  3  4  5  
T  T  F  F  F  F
0  2  5