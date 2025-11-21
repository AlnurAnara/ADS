//Given an array of n strings, find all pairs of identical strings.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int get_hash(string s) {
    int p = 29;
    int p_pow = 1;
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    map<int, vector<int>> hash_map;  // hash -> indices

    // Compute hash for each string and group by hash
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        int h = get_hash(strings[i]);
        hash_map[h].push_back(i);
    }

    // Find pairs with same hash
    cout << "Identical string pairs:" << endl;
    for (auto& pair : hash_map) {
        vector<int>& indices = pair.second;
        // All strings with same hash are potentially identical
        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                // Double-check actual strings to avoid hash collisions
                if (strings[indices[i]] == strings[indices[j]]) {
                    cout << indices[i] << " " << indices[j] << endl;
                }
            }
        }
    }

    return 0;
}

/*
Input:
5
hello
world
hello
test
world

Output:
Identical string pairs:
0 2    (both "hello")
1 4    (both "world")
*/