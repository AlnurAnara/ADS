#include <iostream>
#include <cmath>
using namespace std;

//check whether the input is prime or not
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
    if (isPrime(n)){
    cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}