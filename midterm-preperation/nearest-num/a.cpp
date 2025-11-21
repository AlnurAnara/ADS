#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* nearest number
You are given list of integers and an integer k. Find nearest to k number in the list. Distance between
numbers is deﬁned as absolute value of their diﬀerence. If there are multiple such numbers, choose the
ﬁrst one 
output the index of the num 

i.e.
6
7 8 -10 4 2 -1
5

output:3
*/
int main() {
    int n; 
    cin >> n;
   vector<long long> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long k;
    cin >> k;
    
    long long min_diff = abs(arr[0] - k);
    int index = 0;
    
    for (int i = 1; i < n; i++) {
        long long diff = abs(arr[i] - k);
        if (diff < min_diff) {
            min_diff = diff;
            index = i;
        }
    }
    
    cout << index << endl;
    
    return 0;
}