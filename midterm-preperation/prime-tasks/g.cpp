#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <cmath> 

using namespace std;

// find the superprime
bool isPrime(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false; 
    }
    return true; 
}

int main(){
    vector<int> primes;
    int num = 2;
    int nthSuperPrime;
    int index = 1; // declare the index is form 1
    cin >> nthSuperPrime;
    
    while(nthSuperPrime != primes.size()){
        if(isPrime(num)){
            if(isPrime(index)) // check whether the index is prime 
                primes.push_back(num);
            index++; 
            }
        num++;
    }
    cout << primes.at(primes.size() - 1);

}
/*
On the previous quiz, you needed to find n-th prime for Vanya. 
I think it was very easy, so let’s make it a little harder. You need to find a prime whose index is n-th prime. As an example prime numbers is: 2, 3, 5, 7... have indexes 1,2,3,4... so 2 and 3 indexes are primes too, therefore we have sequence of "superprimes" like: 3, 5, 11, 17... Find n-th superprime.

e.g.
num   2 3 5 7 11 13 17 19...
index 1 2 3 4  5  6  7  8 (because the 1-th line 3 and the 2-nd line 2 are both prime number,so it is superprime)
        1 2    3     4
*/