//Given array and k queries, check if each element exists.
#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &a, int x) {
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        if (a[m] < x) 
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        if (find(a, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}