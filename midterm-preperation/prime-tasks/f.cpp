#include <iostream>
#include <cmath>
using namespace std;

//Just print n-th prime number
bool isPrime(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false; 
    }
    return true; 
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int num = 2;
    while (cnt < n) {
        if (isPrime(num)) {
            cnt++;
            if (cnt == n) {
                cout << num << endl;
                break;
            }
        }
        num++;
    }
    return 0;
}