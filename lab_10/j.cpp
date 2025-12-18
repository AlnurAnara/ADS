/* A vertex is BigFam if it is a root or it has more children than its parent. Count the number of BigFam vertices in the given graph.
Print the number of BigFam vertices*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[100005];
int children_count[100005];
bool used[100005];
int parent[100005];

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph
    for(int i = 1, l, r; i <= m; i++){
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    int ans = 0;
    
    // For each connected component
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            queue<int> q;
            q.push(i);
            used[i] = 1;
            parent[i] = 0; // Root has no parent
            
            // First BFS to establish parent-child relationships and count children
            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(int to : g[v]){
                    if(!used[to]){
                        used[to] = 1;
                        parent[to] = v;
                        children_count[v]++; // v has one more child
                        q.push(to);
                    }
                }
            }
        }
    }
    
    // Reset used for second pass to check BigFam condition
    for(int i = 1; i <= n; i++) used[i] = false;
    
    // Second pass: count BigFam vertices
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            queue<int> q;
            q.push(i);
            used[i] = 1;
            
            // Root is always BigFam
            ans++;
            
            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(int to : g[v]){
                    if(!used[to]){
                        used[to] = 1;
                        q.push(to);
                        
                        // Check if 'to' is BigFam
                        // It has more children than its parent (v)
                        if(children_count[to] > children_count[v]) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}