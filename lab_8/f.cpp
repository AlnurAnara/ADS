#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.length();
    
    // 使用更快的哈希集合
    unordered_set<ll> hashes;
    
    const ll base1 = 131;
    const ll base2 = 13131;
    const ll mod1 = 1e9 + 7;
    const ll mod2 = 1e9 + 9;
    
    // 只用一个循环，避免预计算的开销
    for (int i = 0; i < n; i++) {
        ll h1 = 0, h2 = 0;
        for (int j = i; j < n; j++) {
            // 组合双哈希成一个值
            h1 = (h1 * base1 + s[j]) % mod1;
            h2 = (h2 * base2 + s[j]) % mod2;
            
            // 将双哈希组合成一个ll值
            ll combined = (h1 << 32) | h2;
            hashes.insert(combined);
        }
    }
    
    cout << hashes.size() << endl;
    return 0;
}