/*You are given two numbers A and B 
You can do one of the operations with A in each turn.
Multiply number by 2.
Decrease the number by 1.

You need to find the minimum number of operations, to make A equal to B

Also print the every element after doing the operation.


so the mean idea is to work backwards from B to A:
If current B<A
: We must have arrived here by subtracting 1. So, in reverse, we Add 1.
If current B>A:
If B is even, we divide by 2 (fastest way to reduce magnitude).
If B is odd, we cannot have arrived via multiplication (since x⋅2)is always even). 
We must have arrived via subtraction. So, in reverse, we Add 1 to make it even.
*/

#include <iostream>
#include <vector>   
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;

    vector<int> path;
    path.push_back(b);  // Initialize path with the target value b

    while (b > a) {
        if (b % 2 == 0) {
            b /= 2;
        } else {
            b += 1;
        }
        path.push_back(b);  // Store each intermediate value
    }
    while (b < a) {
        b += 1;
        path.push_back(b);  // Store each intermediate value
    }
    cout << path.size() - 1 << endl; // Number of operations is size - 1
    for (int i = path.size() - 2; i >= 0; i--) {  
        /*path.size() -2 means we just output the second to last elemment down to 0
        if it is path.size()-1 which output the whole elemment during the operation */

        cout << path[i] << " ";
    }
    cout << endl;
    return 0;

}