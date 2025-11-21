#include <iostream>
using namespace std;

// TC for hash is O (n*m)
int get_hash(string s) {
    int p = 29;
    int p_pow = 1;  // p^0
    int h = 0;

    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main() {
    cout << "hash('abc') = " << get_hash("abc") << endl;
    cout << "hash('hello') = " << get_hash("hello") << endl;
    cout << "hash('world') = " << get_hash("world") << endl;

    return 0;
}
/*hash = 'a' × 29^0 + 'b' × 29^1 + 'c' × 29^2
     = 97 × 1 + 98 × 29 + 99 × 841
     = 97 + 2842 + 83259
     = 86198
*/