#include <iostream>
#include <vector>
using namespace std;

// 最小堆的堆化函数
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// 使用堆排序找第k小的元素
int findKthSmallest(vector<int>& arr, int k) {
    int n = arr.size();
    
    // 构建最小堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
    
    // 执行k-1次提取操作
    for (int i = n - 1; i >= n - k + 1; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    
    return arr[0]; // 第k小的元素在堆顶
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    int k = 3;
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    int kthSmallest = findKthSmallest(arr, k);
    cout << "the " << k << "th smallest element is: " << kthSmallest << endl;
    
    return 0;
}