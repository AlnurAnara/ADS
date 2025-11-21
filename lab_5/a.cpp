#include <iostream>
#include <queue>
using namespace std;

/*它计算将 N 个数组（或文件、线段等）合并成一个单一实体的最小总代价。
Explanation for the first test case:

[6, 5, 3, 9] –> First, merge arrays of lengths 5 and 3 that will cost 8.

[6, 8, 9] –> Next, merge arrys of lengths 6 and 8 that will cost 14.

[14, 9] –> Finally, merge the remaining two arrays that will cost 23.

Therefore, the total cost for merging all arrays is 8 + 14 + 23 = 45.
*/

int main() {
    
    priority_queue<long long,vector<long long>,greater<long long> >pq; // this is representative of min heap 
    
    long long n, x, sum = 0;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }
    
    while(pq.size() != 1){ //循环直到堆中只剩下一个元素
        long long u = pq.top(); // 取出并移除堆中最小的元素 u
        pq.pop(); 
        long long v = pq.top(); // 取出并移除堆中次小的元素 v
        pq.pop();
        pq.push(u + v);  //将 u 和 v 合并后的新长度 (u+v) 重新推入堆中。
        sum += u + v; //将本次合并的代价 (u+v) 累加到 sum 中。
    }
    cout << sum;
    
    return 0;
}