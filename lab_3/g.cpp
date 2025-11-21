#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 5;

/*help him ﬁnd the least possible capacity of the
bag to deliver all gifts during no more than f ﬂights.

Input
The ﬁrst line of the input contains two integers n and f - number of islands in the Duck Kingdom and
number of ﬂights
The second line of the input contains n integers ci - number of children in the ith island

so we need to find the minimum capacity x such that:
sum(ceil(c_i / x)) <= f

n=3, f=6
c = [10, 10, 10]
如果容量 x=5：

岛屿1：ceil(10/5) = 2 次

岛屿2：ceil(10/5) = 2 次

岛屿3：ceil(10/5) = 2 次
总飞行次数 = 6 ≤ f ✅

如果 x=4：

每个岛屿需要 ceil(10/4) = 3 次
总飞行次数 = 9 > f ❌

所以最小容量是 5。

*/
int main() {
    
    long long n, f; // 声明岛屿数 n 和最大允许的飞行次数 f
    long long a[N]; // 存储每个岛屿的孩子数 c_i
    
    cin >> n >> f;
    
    for(int i = 1; i <= n; i++) cin >> a[i];

    long long l = 0, r = INT_MAX;
    
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        long long sum = 0; // 统计总飞行次数
        for(int i = 1; i <= n; i++){
            sum += (a[i] + mid - 1) / mid;
        }
        if(sum > f) l = mid;
        else r = mid;
    }
    cout << r;
    
    return 0;
}