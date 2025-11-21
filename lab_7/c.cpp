#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//find the common elements between two arrays
int main() {
    
    int n, m, x;
    vector<int> v, w;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> x, v.push_back(x);
    
    for(int i = 1; i <= m; i++) cin >> x, w.push_back(x);
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    
    for(int i = 0, j = 0; i < v.size() && j < w.size();){
        if(v[i] == w[j]) {
            cout << v[i] << ' ';
            i++, j++;
        } else {
            if(v[i] < w[j])i++;
            else j++;
        }
    }
    
    return 0;
}