#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Recursive DFS function  O(V + E) time complexity
void dfsRecursive(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    // Mark node as visited and process it
    visited.insert(node);
    
    // Visit all unvisited neighbors
    for (auto neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfsRecursive(neighbor, graph, visited);
        }
    }
}

// Wrapper function
void dfs(int start, unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    cout << "DFS Traversal: ";
    dfsRecursive(start, graph, visited);
    cout << endl;
}

int main() {
    // Create graph as adjacency list
    unordered_map<int, vector<int>> graph;
    
    // Add edges
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5, 6};
    graph[3] = {};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};
    
    // Perform DFS starting from node 0
    dfs(0, graph);
    
    return 0;
}