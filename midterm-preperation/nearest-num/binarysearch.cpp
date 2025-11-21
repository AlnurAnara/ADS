#include <iostream>
#include <vector>
using namespace std;

/*
find nearest elements in a sorted array with binary search
The largest element ≤ x (closest from the left)
The smallest element ≥ x (closest from the right)
*/
pair<int,int> nearest_elements(vector<int>& a, int x) {
    int n = a.size();
    int l = -1, r = n; // conceptual -∞ and +∞
    
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }
    
    int leftVal = (l >= 0 ? a[l] : INT_MIN);
    int rightVal = (r < n ? a[r] : INT_MAX);
    return {leftVal, rightVal};
}

int main() {
    vector<int> a = {3, 5, 10, 11, 13, 18, 25, 27, 31};
    int x = 20;
    auto [leftVal, rightVal] = nearest_elements(a, x);
    cout << "Closest left: " << leftVal << ", closest right: " << rightVal << "\n";
    return 0;
}