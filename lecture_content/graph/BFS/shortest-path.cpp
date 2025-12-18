#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

/*In an undirected graph, you need to find the shortest path between two vertices.
Print the length of the shortest path. If the path does not exist, print a single number 
.
*/
map<int, int> shortestDistance(map<int, vector<int>>& graph, int startNode) {
    queue<int> q;
    set<int> visited;
    map<int, int> distance; // distance[node] = 最短步数

    visited.insert(startNode); // 起点是第一个被访问的节点 → 标记为 visited
    distance[startNode] = 0;// 起点到自己的距离 = 0
    q.push(startNode);  // 起点入队 → BFS 从这里开始

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // 遍历 current 的每一个邻居
        for (int neighbor : graph[current]) {
            if (!visited.count(neighbor)) {  // 如果这个邻居没访问过
                visited.insert(neighbor);  // 标记：避免重复入队
                distance[neighbor] = distance[current] + 1; // 多走一条边
                q.push(neighbor);
            }
        }
    }

    return distance;
}

int main(){
    int n;
    cin >> n;
    map<int, vector<int>> graph;

    //create graph from adjacency matrix
    for (int i = 1; i <= n; i++) {
        for(int j=1; j<=n; j++){
            int edge;
            cin >> edge;
            if(edge == 1){ // there is an edge between i and j
                graph[i].push_back(j);
            }
        }
    }

    int start, end;
    cin >> start >> end;

    // 特殊情况：如果起点就是终点，距离为 0
    if (start == end) {
        cout << 0 << endl;
        return 0;
    }
    map<int, int> result = shortestDistance(graph, start);

    // 检查 map 中是否有终点的记录
    if (result.count(end)) {
        cout << result[end] << endl; // 输出从 start 到 end 的最短距离
    } else {
        // 如果 map 里找不到 end，说明无法到达
        cout << -1 << endl;
    }

    return 0;
}
