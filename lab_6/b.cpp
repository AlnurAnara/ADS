#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ﬁnd the common elements between two arrays
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
            i++, j++; //同时将两个指针向后移动，继续寻找下一个可能的交集元素。
        } else {
            if(v[i] < w[j])i++; //如果 v 中的元素较小，说明 v[i] 不可能在 w 的后续部分出现，所以将指针 i 向后移动。
            else j++;
        }
    }
    
    return 0;
}