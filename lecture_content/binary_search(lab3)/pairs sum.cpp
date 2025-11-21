#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int binarySeachRecursion(vector<int> arr, int target, int left, int right) {
    if (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) { // 目标在右侧，缩小左边界
            left = mid + 1;
            return binarySeachRecursion(arr, target, left, right);
        } 
        right = mid - 1;// 目标在左侧，缩小右边界
        return binarySeachRecursion(arr, target, left, right);
    }
    
    
    return -1;
    
}

int countPairs(vector<int>arr, int target){
    sort(arr.begin(), arr.end()); // sort the array

    int left = 0;
    int right = arr.size() - 1;
    int count = 0;

    while(left <= right){
        if(arr[left] + arr[right] < target){
            count += right - left;
            left++;
            
        }else  {
            right--;
        }
    }
    /*for (int i = 0; i < arr.size(); i++){
        int target = arr[i];
        int result = binarySeachRecursion(arr, target, 0, arr.size() - 1);
        if (result != -1) {
            count++;
        }
    }
     */
    return count;
}
int main () {
    /*
    测试用例1：
    输入：
    9
    1 2 3 4 5 6 7 8 9
    5
    输出：
    目标值 5 找到，索引为 4
    */
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = binarySeachRecursion(arr, target, 0, arr.size() - 1);
    if (result != -1) {
        cout << "目标值 " << target << " 找到，索引为 " << result << endl;
    } else {
        cout << "目标值 " << target << " 未找到" << endl;
    }
    return 0;
}