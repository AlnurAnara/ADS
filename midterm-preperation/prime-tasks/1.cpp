#include <iostream>
using namespace std;

/*given positive integer n,find the number of unique prime number that devide n
给定一个正整数 n，找出能整除 n 的不同质数的个数
i.e. 12=2^2 * 3,so the answer is 2
*/
bool check(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    } //O(sqrt(n))
    return true;
}

int main() {
    
    int n, cnt = 0;
    
    cin >> n;
    
    for(int i = 2; i * i <= n; i++){
        if(check(i) && n % i == 0) cnt++;
    } // O(n)
    
    cout << cnt;
    
    return 0;
}