#include <iostream>
#include <algorithm>
using namespace std;
/*
有 N 个对手，每个对手有一个力量值 a[i]。

有 P 个回合，每回合 Mark 有一个力量值 p_i。

每回合 Mark 可以击败所有力量值 ≤ p_i 的对手。

每回合结束后，所有对手复活（所以每回合对手集合不变）。

每回合要输出：

击败的对手数量

这些对手的力量值总和

N = 7
a = [7, 9, 1, 8, 2, 6, 2]
P = 2
p = [4, 8]
第1回合 p=4：击败力量 ≤4 的对手：1, 2, 2 → 数量=3，力量和=5

第2回合 p=8：击败力量 ≤8 的对手：7, 1, 8, 2, 6, 2 → 数量=6，力量和=26

3 5
6 26
*/

const int N = 1e6 + 5;

int main() {
    
    int n, m, x;
    int a[N], pref[N];
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n); //对竞争者的力量进行升序排序
    
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];// sum of their powers
    
    cin >> m;
    
    for(int i = 1; i <= m; i++){
        cin >> x;
        int l = 0, r = n+1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[mid] > x) r = mid;
            else l = mid;
        }
        cout << l << " " << pref[l] << "\n";
    }
    
    return 0;
}