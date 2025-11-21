#include <iostream>
#include <climits>
using namespace std;

/*有 N 袋金子，每袋有 bags[i] 根金条。警长 H 小时后回来。

罗宾每小时偷 K 根金条，但只能从一个袋子里偷。
如果一个袋子里的金条少于 K，他就偷光该袋，这个小时结束。
目标：找到最小的 K，使得罗宾能在 H 小时内偷完所有金条

N=4, H=8
bags = [3, 6, 7, 11]
如果 K=4：

袋子1：3根 → 需要 1 小时（偷光）
袋子2：6根 → 需要 2 小时（4+2）
袋子3：7根 → 需要 2 小时（4+3）
袋子4：11根 → 需要 3 小时（4+4+3）
总小时 = 1+2+2+3 = 8 ≤ H ✅

如果 K=3：

袋子1：1 小时
袋子2：2 小时
袋子3：3 小时（3+3+1）
袋子4：4 小时（3+3+3+2）
总小时 = 1+2+3+4 = 10 > H ❌

所以最小 K=4
*/
const int N = 1e4 + 5;

int main() {
    
    long long n, f;
    long long a[N];
    
    cin >> n >> f;
    
    for(int i = 1; i <= n; i++) cin >> a[i];

    long long l = 0, r = INT_MAX;
    
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            sum += (a[i] + mid - 1) / mid;
        }
        if(sum > f) l = mid;
        else r = mid;
    }
    cout << r;
    
    return 0;
}