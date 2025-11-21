//哥德巴赫猜想：给定一个偶数n，找到两个素数p和q使得p+q=n。
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    // 从最小的素数开始尝试
    for (int p = 2; p <= n / 2; p++) {
        if (isPrime(p)) {
            int q = n - p;
            if (isPrime(q)) {
                cout << p << " " << q << endl;
                return 0;
            }
        }
    }
    
    return 0;
}