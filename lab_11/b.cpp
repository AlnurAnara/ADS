#include <iostream>
#include <vector>  
#include <climits>
using namespace std;

/*任何两个岛屿之间必须有一条通路，其价格是两座岛上鸭子数量之和。，目标是找到连接所有岛屿所需的最小总花费
Total Cost = (n-2)*Min+Sum*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;
    long long min = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        min = min(min, a[i]);
    }

    cout << sum + (n - 2) * min;
    return 0;
}
