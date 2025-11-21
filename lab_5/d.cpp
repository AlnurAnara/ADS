#include <iostream>
#include <queue>
using namespace std;

/*
Mark is making an experiment with mixtures of different densities. 
For his experiment he wants all of the mixtures to have a density  >= m.

He uses the following formula to obtain a combined mixture: d_new= d_least + 2 * d_secondleast  
where d_new is the density of the new mixture, d_least is the smallest density among all mixtures and  
 d_secondleast  is the second smallest density among all mixtures.

Mark repeats the mixing until he gets all the mixtures with the density >=m.

You are given the amount of densities of mixtures n and the target density m. 
How many times Mark should mix his mixtures to get the densities of all mixtures ?
*/

int main() {
    
    priority_queue<long long, vector<long long>, greater<long long> >pq;
    
    long long n,m, x, cnt = 0;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }

    while(pq.top() < m && pq.size() > 1){ //只要堆中还有两块及以上的石头，就继续
        long long u = pq.top(); 
        pq.pop(); // 取出并移除堆中最小的元素 u
        long long v = pq.top(); // 取出并移除堆中次小的元素 v
        pq.pop();
       
        pq.push(u +2* v); 
        cnt++;
    }

    if(pq.top()  < m) cout << -1;
    else cout << cnt;

    return 0;
}