#include <iostream>
#include <queue>
using namespace std;

/*
task:With each turn, we choose the two heaviest rocks and smash（粉碎） them together. 
Suppose the stones have weights x and y with x <= y.
If x == y, both stones are totally destroyed. 
If x < y, the stone of weight x is totally destroyed, 
and the stone of weight y has a new weight y-x. 

i.e.
6
2 7 4 1 8 1

We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] 
then, we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] 
then, we combine 2 and 1 to get 1 so the array converts to [1,1,1] 
then, we combine 1 and 1 to get 0 so the array converts to [1] 
then that’s the value of last stone.
*/

int main() {
    
    priority_queue<long long>pq; // this is representative of max heap 
    
    long long n, x, sum = 0;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){ //只要堆中还有两块及以上的石头，就继续
        long long u = pq.top(); 
        pq.pop(); // 取出并移除堆中最大的元素 u
        long long v = pq.top(); // 取出并移除堆中次大的元素 v
        pq.pop();
        if (u != v) pq.push(u - v); 
    }

    if(pq.size() == 0) cout << 0;
    else cout << pq.top();
    
    return 0;
}