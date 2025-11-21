#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Given two strings A and B. Your task is to find the minimum number of times A has to be repeated such that B is a substring of it. 
If B cannot be found in A after it’s extension, return -1. If A already contains B, the number of repetitions is equal to one by default.
Examples
Input
abcd
cdabcdab
Output
3
Input
aaa
a
Output
1
*/
bool kmp_search(const string &s, const string &p) {
    int n = s.length();
    int m = p.length();
    if (m == 0) return true;
    if (n < m) return false;

    // create lps array
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m;) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int i = 0, j = 0;
    while (i < n) {
        if (p[j] == s[i]) { 
            i++;
            j++;
        }
        if (j == m) {
            return true;
        } else if (i < n && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

int main() {
    string A, B;
    getline(cin, A);
    getline(cin, B);

    if (B.empty()) {
        cout << 1 << endl;
        return 0;
    }

    int count = 1;
    string S = A;
    
    // 最大重复次数：足够覆盖 B 并且多两个 A 的长度
    int max_repeats = (B.length() / A.length()) + 3;
    
    for (int i = 0; i < max_repeats; i++) {
        if (S.length() >= B.length() && kmp_search(S, B)) {
            cout << count << endl;
            return 0;
        }
        S += A;
        count++;
    }

    cout << -1 << endl;
    return 0;
}