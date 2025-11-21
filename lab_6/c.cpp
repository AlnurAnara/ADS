#include <iostream>
#include <algorithm>
#include <cmath>   // Required for abs()
using namespace std;

/*You are given a list of integer points in a line. 
Find the pair of points with the least absolute difference. If there are more than one pairs output them all.
Input
6
-20 -3916237 -357920 -362060 30 6246457
Output
-20 30
*/
int main() {
    
    int n, a[200005];
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a , a + n);

    int mn = abs(a[1] - a[0]);
    for(int i = 2; i < n; i++) mn = min(mn, abs(a[i] - a[i-1]));

    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i-1]) == mn) cout << a[i-1] << ' ' << a[i] << ' ';
    }
    cout << endl;    
    return 0;
}
