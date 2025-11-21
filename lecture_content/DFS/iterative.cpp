#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// Basic iterative DFS
void dfsIterative(int start, unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    stack<int> st;
    
    st.push(start);
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        // Process node if not visited
        if (!visited.count(node)) {
            visited.insert(node);
            cout << node << " ";
            
            // Add all unvisited neighbors to stack
            for (auto neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    st.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int>> graph;
    
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5, 6};
    graph[3] = {};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};
    
    dfsIterative(0, graph);
    return 0;
}