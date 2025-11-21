#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfsRecursive(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    visited.insert(node);
    cout << node << " ";
    
    for (auto neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfsRecursive(neighbor, graph, visited);
        }
    }
}

// DFS for all components in disconnected graph
void dfsAllComponents(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    int componentCount = 0;
    
    for (auto& e: graph) {
        int node = e.first;
        if (!visited.count(node)) {
            cout << "Component " << ++componentCount << ": ";
            dfsRecursive(node, graph, visited);
            cout << endl;
        }
    }
}

int main() {
    // Disconnected graph with 2 components
    unordered_map<int, vector<int>> graph;
    
    // Component 1: 0-1-2
    graph[0] = {1};
    graph[1] = {0, 2};
    graph[2] = {1};
    
    // Component 2: 3-4-5
    graph[3] = {4};
    graph[4] = {3, 5};
    graph[5] = {4};
    
    dfsAllComponents(graph);
    
    return 0;
}