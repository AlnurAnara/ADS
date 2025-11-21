#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Given two sorted integer arrays a and b, merge a into b as one sorted array.
Input
5
4 5 6 7 10
5
2 4 6 7 8
Output
2 4 4 5 6 6 7 7 8 10 
*/
int main() {
    
    int n, m, x;
    vector<int> v;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x, v.push_back(x);
    
    cin >> m;
    
    for(int i = 1; i <= m; i++) cin >> x, v.push_back(x);
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)  cout << v[i] << ' ';
    
    return 0;
}
