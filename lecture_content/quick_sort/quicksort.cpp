#include <iostream>
#include <vector>
using namespace std;

// 分区函数
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];  // 选择最后一个元素作为基准
    int pos = left ;        // 较小元素的索引
    
    for (int i = left; i < right; i++) {
        // 如果当前元素小于等于基准
        if (arr[i] <= pivot) {  
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    
    // 将基准放到正确位置
    swap(arr[pos], arr[right]);
    return pos;
}

// 快速排序主函数                                          // space complexity:the average :O(log n) and the worst:O(n)
void quickSort(vector<int>& arr, int left, int right) {  // time complexity : the average: O(nlog n) and the worst: O(n^2)
    if (left < right) {
        // 获取分区点
        int pi = partition(arr, left, right);
        
        // 递归排序分区
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}




// 测试代码
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "排序前: ";
    
    for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "排序后: ";
    for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
    
    return 0;
}