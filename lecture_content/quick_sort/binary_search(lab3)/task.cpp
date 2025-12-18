//Given array and k queries, check if each element exists.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() -1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) { // 目标在右侧，缩小左边界
            left = mid + 1;
        } else {
            right = mid - 1;// 目标在左侧，缩小右边界
        }
    }
    return -1;// 未找到

}

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }

    int x;
    for(int i=0;i<k;i++){
        cin >> x;
        if(binarySearch(arr,x)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}