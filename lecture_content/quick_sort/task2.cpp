//find the k-th largest element in an array 
/* what is the pibot point has duplicates 
the solution is to put the duplicates into the middle of the array 
    2,1,5,6,3,5
2,1,3     5,5        6
        p1  p2
        p1 < n-k < p2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];  
    int pos = left ;       
    
    for (int i = left; i < right; i++) {
    
        if (arr[i] <= pivot) {  
            swap(arr[i], arr[pos]);
            pos++;
        }
    }

    swap(arr[pos], arr[right]);
    return pos;
}

int findKthLargest(vector<int>& arr, int k) { 
    int n = arr.size();
    int pos = n-k;
    int left = 0;
    int right = n-1;

    while(left <= right){
        
        int pindex = partition(arr, left, right);

        if (pindex == pos) {
            
            return arr[pindex];

        } else if (pindex < pos) {
            
            left = pindex + 1;  
        } else { 
            right = pindex - 1;
        }
    }

    return -1; 
}


int main() {
    vector<int> arr = {2,1,3,6,5,5};
                                
    int k;
    cin >> k;
    int result = findKthLargest(arr, k);
    
    cout << "the k-th largest element:" << result << endl;
    
    return 0;
}