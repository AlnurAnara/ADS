#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct DSU{
    vector<int> p, R;
    DSU(int v){
        for(int i=0;i<v;i++){
            p[i]=i;
            R[i]=1;
        }

    }
    int find(int i){
        if (p[i]==i){
            return i;
        }else{
            return p[i]=find(p[i])
        }
    }

    bool unite(int x, int y){
        int p1=find(x);
        int p2=find(y);
        if(p1!=p2){
            if(R[p1]> R[p2]){
                p[p2] =p1;
            }else if(R[p1]< R[p2]){
                p[p1] =p2;
            }else{
                p[p2]=p1;
                R[p1]++;

            }
            return true;
        }
        else return false;
    }
}

//custom comparative function
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

int Kruskal(vector<vector<int>> &el, int V){ //O(ElogE)
    sort(el.begin(), el.end(), cmp);  // O(nlogn)
    DSU dsu(V);
    int total_weight = 0;
    int count = 0;

    for(auto& edge: el){
        int x = edge[0]; int y = edge[1]; int w = edge[2];
        if (dsu.find(x) != dsu.find(y)){
            dsu.unite(x, y);
            total_weight += w;
            count++;

            if (count == V - 1) break;
        }

        return total_weight;
    }
}
//O(ElogE) time complexity

