#include <iostream>
#include <vector>

using namespace std;

// Compute hash of entire string
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

// Compute prefix hash array
vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;  // p^1

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Precompute powers of p
    vector<int> p(s1.size());
    p[0] = 1;
    for (int i = 1; i < s1.size(); i++)
        p[i] = p[i - 1] * 29;

    // Hash of pattern
    int h_s2 = get_hash(s2);

    // Prefix hashes of text
    vector<int> h = get_h(s1);

    int n = s1.size();
    int m = s2.size();

    // Find all occurrences
    for (int i = 0; i < n - m + 1; i++) {
        int j = i + m - 1;  // End of current window

        // Get hash of substring s1[i...j]
        int hash = h[j];
        if (i > 0)
            hash = hash - h[i - 1];

        // Compare with pattern hash
        // hash = actual_hash × p^i, so compare with h_s2 × p^i
        if (hash == h_s2 * p[i])
            cout << i << " ";
    }

    return 0;
}

/*Example Trace
Input:

s1 = "ababcab"
s2 = "ab"
Step 1: Compute h_s2 (hash of "ab")

h_s2 = 'a' × 29^0 + 'b' × 29^1
     = 97 × 1 + 98 × 29
     = 97 + 2842
     = 2939
Step 2: Compute prefix hashes of s1

h[0] = 97              (hash of "a")
h[1] = 2939            (hash of "ab")
h[2] = 86238           (hash of "aba")
h[3] = 2499954         (hash of "abab")
...
Step 3: Check each position

Position 0: substring "ab"
  hash = h[1] = 2939
  h_s2 × p[0] = 2939 × 1 = 2939
  Match! Output: 0

Position 1: substring "ba"
  hash = h[2] - h[0] = 86238 - 97 = 86141
  h_s2 × p[1] = 2939 × 29 = 85231
  No match

Position 2: substring "ab"
  hash = h[3] - h[1] = 2499954 - 2939 = 2497015
  h_s2 × p[2] = 2939 × 841 = 2471699
  Match! Output: 2
...
*/