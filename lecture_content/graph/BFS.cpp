#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;


// BFS introduces a queue data structure to explore nodes level by level
//TC: O(V + E) 
//SC: O(V) for the visited set and the queue in the worst case
 // To keep track of visited nodes,so the TC will be constant

set<int> BFS(map<int, vector<int>>& graph, int startNode) {
    queue<int> q;
    set<int> visited;
    
    visited.insert(startNode);
    q.push(startNode);
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        for (auto neighbor : graph[currentNode]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    return visited;  // Return all visited nodes
}