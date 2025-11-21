// use binary search determine whether the given num is in the array or not
#include <iostream>
#include <algorithm> 
using namespace std;


int main() {
    int n;
    cin >> n;

    int a[1005];
    for(int i = 0; i < n; i++) cin >> a[i];
   

    // CRUCIAL STEP: Sort the array before performing binary search.
    // std::sort sorts the elements in the range [a, a + n)
    sort(a, a + n);

    int x;
    cin >> x;

    // --- Binary Search Logic ---
    bool found = false;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == x) {
            found = true;
            break; 
        }
       
        else if (a[mid] < x) {
            left = mid + 1;
        }
       
        else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}