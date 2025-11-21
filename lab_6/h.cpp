#include <iostream>
#include <vector>
using namespace std;

/*
You have one letter. Your task is to find "balanced" char in array. 
"Balanced" char is the smallest in array, but more than your letter.

Input format
You are given integer n. n- number of elements in array.
Then goes an array. Array has only sorted lowercase letter.

Output format
Print the "balanced" letter.

Examples
Input
3
c f g
a
Output
c
*/
int main() {
    int n;
    cin >> n;
    
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    char target;
    cin >> target;
    

    for (int i = 0; i < n; i++) {
        if (arr[i] > target) {
            cout << arr[i] << endl;
            return 0;
        }
    }
    
    cout << arr[0]<< endl;
    
    return 0;
}