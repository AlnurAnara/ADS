#include <iostream>
#include <unordered_set>
using namespace std;

/*Given string s. How many different substrings it contains? IMPROTANT!!
the time complexity of this code is O(n^2)
but when the size of the string is large,this code would be error*/
int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    unordered_set<long long> hashes;
    const long long base = 131;
    const long long mod = 1e9 + 7;
    
    for (int i = 0; i < n; i++) {
        long long hash_val = 0;
        for (int j = i; j < n; j++) {
            // 计算子串 s[i..j] 的哈希值
            hash_val = (hash_val * base + s[j]) % mod;
            hashes.insert(hash_val);
        }
    }
    
    cout << hashes.size() << endl;
    return 0;
}