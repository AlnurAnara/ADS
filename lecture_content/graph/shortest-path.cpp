#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// 返回从 startNode 出发到每个点的“最少边数”距离
// 不可达的点不出现在 distance 里
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
