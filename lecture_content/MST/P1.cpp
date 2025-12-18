#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 
MST??
PRIM'S: cutting off other nodes from each node (traversing from each node by the SHORTEST and unvisited path first)

MST by the end of the algo:
        0 1 2 3 4 5 6 7 8
in MST  T T T T T T T T T
        0 4 8 7 9 4 2 1 2
*/

int minIdx(vector<bool> inMST, vector<INT> D){
    min_val = INT_MAX;
    min_idx = -1;
    for(int i = 0; i < inMST.size(); i++){
        if D[i] < min_val && !inMST[i]{ 
            min_val = D[i];
            min_idx = i;
        } 
        return min_idx;
    }
}

Prim(vector<vector<int>> G, int V){ //O(V^2) SC:O(V)
    vector<bool> inMST(V, False);// check which node is in the  inMST
    vecotr<int> D(V, INT_MAX); // initilise the distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater(pair<int, int>);
    //                   W   Vert
    pq.push({0,0});

    //V-1

    total_weight = 0;
    while(!pq.empty()){
        next = pq.top();
        pq.pop();
        
        inMST[next] = True;
        total_weight += D[next];

        for(auto& nei: G[next]){
            if(!inMST[nei.second]) pq.push(nei);
        }

        total_weight += D[next];

    }
}
//O(V^(2)) time complexity