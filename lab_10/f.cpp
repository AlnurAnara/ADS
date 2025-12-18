/* He takes two vertices and checks to see if they are in the same component.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int qu, x;
vector<int> g[100005];
bool used[100005];

int main() {
    int n,m,l,r;
    cin >> n >> m;

    // create graph from edges
    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    
    cin >> l >> r;// input two vertices to check if they are in the same component

    queue<int> q;

    q.push(l);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int to : g[v]){
            if(!used[to]){//If neighbor to hasn't been visited:
                used[to] = 1;  // mark as visited
                q.push(to); // add it to the queue
            }
        }
    }
    if(used[r]) cout << "YES";
    else cout << "NO";
    /*If vertex r was marked as visited during BFS starting from l:
    Output "YES" (same connected component)
    Else:Output "NO"
    */


    return 0;
}