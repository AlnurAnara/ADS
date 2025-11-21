#include <iostream>
#include <vector>
using namespace std;


int binarySeachRecursion(vector<int> arr, int target, int left, int right) {
    if (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) { 
            left = mid + 1;
            return binarySeachRecursion(arr, target, left, right);
        } 
        right = mid - 1;
        return binarySeachRecursion(arr, target, left, right);
    }
    
    
    return -1;
    
}


int main () {
  
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = binarySeachRecursion(arr, target, 0, arr.size() - 1);
    cout << result << endl;
    
    return 0;
}