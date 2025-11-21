/*Binary Search：二分查找是一种在有序数组（或任何有序集合）中快速查找特定元素的算法。
    它的核心思想是“分而治之”，通过每次将搜索范围缩小一半来极快地定位目标值。
Time Complexity: O(log n)
Space Complexity: O(1)
*/ 
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

int main () {
    /*
    测试用例1：
    输入：
    9
    1 2 3 4 5 6 7 8 9
    5
    输出：
    index:4
    */
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int target = 5;
    int result = binarySearch(arr, target);
    
    cout << "index:" << result << endl;
    return 0;
}