#include <iostream>
#include <queue>
using namespace std;

/*Nurdana 最多只能保留 k 个盒子。初始时没有盒子。 solve the problem with heap
两种操作：
insert n — 爸爸给一个有 n 块饼干的盒子
print — 输出当前能拥有的最大饼干数（即当前所有盒子中，最多选 k 个盒子的饼干数之和）
注意：
如果盒子数 ≤ k，那么所有盒子的饼干都算上。
如果盒子数 > k，那么只保留饼干数最多的 k 个盒子，求和。
6 4
print
insert 9
insert 6
print
insert 10
print

print → 当前没有盒子 → 输出 0

insert 9 → 盒子：[9]

insert 6 → 盒子：[9, 6]

print → 盒子数 2 ≤ k=4，全选：9+6=15 → 输出 15

insert 10 → 盒子：[10, 9, 6]

print → 盒子数 3 ≤ k=4，全选：10+9+6=25 → 输出 25

0           
15
25

*/
int main() {
    
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    
    long long q, k, x, sum = 0;
    string s;
    
    cin >> q >> k;
    
    for(int i = 1; i <= q; i++){
        cin >> s;
        if(s == "insert"){
            cin >> x;
            if(pq.size() == k){
                long long u = pq.top();
                sum -= u; //无条件移除旧的堆顶 u，并从 sum 中减去 u。
                pq.pop();
                pq.push(max(u, x));
                sum += max(u, x);
            } else {
                pq.push(x);
                sum += x;
            }
        }
        else {
            cout << sum << endl;
    }
}
    
    return 0;
}