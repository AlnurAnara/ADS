#include <iostream>
#include <queue>
using namespace std;

/*有 n 行座位，每行初始有 a[i] 个空座位。
票价规则：如果某行有 k 个空座位，那么该行的票价就是 k。
有 x 个人排队买票。
目标：安排这 x 个人到不同行，使得总收入最大。
关键点：当一个人坐在某行时，该行的空座位数减少 1，因此该行的票价也会减少 1
The ﬁrst line consists of n and x；
n denotes the number of seating rows in the stadium
x denotes the number of football fans waiting in line to get a ticket for the match

*/
int main() {
    
    priority_queue<long long>pq;
    
    long long n, k, x, sum = 0;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }
    
    while(k--){
        sum += pq.top();
        int u = pq.top();
        pq.pop();
        pq.push(u - 1);
    }
    
    cout << sum;
    
    return 0;
}