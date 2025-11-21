#include <iostream>
using namespace std;

const int N = 2e5 + 123;

int main() {
    
    int n, k;
    int x1[N], x2[N], y1[N], y2[N];
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){

        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; 
    };
    
    //low and high上界和下界 分别是1和10^9
    int l = 1, r = 1000000000;
    int cnt = 0;
    
    while(l + 1 < r){
        int mid = (l + r) / 2;
        cnt = 0;
        
        for(int i = 1; i <= n; i++)
            if(x2[i] <= mid && y2[i] <= mid) cnt++;
        
        if(cnt >= k) r = mid; 
        /*如果当前边长 mid 可以覆盖至少 K 只羊（cnt >= k）
        为了找到最小的可行边长，我们将上界 r 缩小到 mid，继续在 [l,mid] 范围内寻找更小的解。
       
        如果当前边长 mid 不能覆盖至少 K 只羊（cnt < k）
        说明边长 mid 太小，无法覆盖 K 只羊。
        为了增加边长，我们将下界 l 增大到 mid，继续在 [mid,r] 范围内寻找更大的解。
        */
        
        else l = mid;
    }
    cout << r; // minimum length of square 
    
    return 0;
}